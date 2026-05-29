#include "main.h"

#include <utility>

double calculate_total_reward(int blocks_mined) {
    // TODO: multiply blocks_mined by MINING_REWARD and return the result
    return blocks_mined * MINING_REWARD;
}

bool is_valid_tx_fee(double fee) {
    // TODO: return true if fee is between 0.00001 and 0.01 BTC (inclusive bounds up to you)

    if (fee >= 0.00001 && fee <= 0.01) return true;

    return false;
}

bool is_large_balance(double balance) {
    // TODO: return true if balance > 50.0 BTC

    if (balance > 50.0) return true;

    return false;
}

std::string tx_priority(int size_bytes, double fee_btc) {
    // TODO: compute fee rate (fee_btc / size_bytes) and return "high" / "medium" / "low"
    //       high   >= 0.00005
    //       medium >= 0.00001
    //       otherwise low

    const double fee_rate = fee_btc / size_bytes;

    if (fee_rate >= 0.00005) return "high";

    if (fee_rate >= 0.00001) return "medium";

    return "low";
}

bool is_mainnet(std::string network) {
    // TODO: lowercase `network` and return true iff it equals "mainnet"

    std::transform(network.begin(), network.end(), network.begin(), ::tolower);

    if (network == "mainnet") return true;

    return false;
}

bool is_in_range(double value) {
    // TODO: return true iff 100 <= value <= 200

    if (value >= 100 && value <= 200) return true;

    return false;
}

bool is_same_wallet(const Wallet& w1, const Wallet& w2) {
    // TODO: return true iff both refs name the same object in memory (compare addresses)

    if (std::addressof(w1) == std::addressof(w2)) return true;

    return false;
}

std::string normalize_address(std::string address) {
    // TODO: strip leading/trailing whitespace and lowercase the address

    std::transform(address.begin(), address.end(), address.begin(), ::tolower);

    address.erase(std::remove(address.begin(), address.end(), ' '), address.end());

    return address;
}

std::vector<int> add_utxo(std::vector<int> utxos, int new_utxo) {
    // TODO: append new_utxo to utxos and return the updated vector

    utxos.emplace_back(new_utxo);

    return utxos;
}

std::optional<std::pair<std::size_t, double>> find_high_fee(const std::vector<double>& fees) {
    // TODO: return (index, fee) of the first fee > 0.005, or std::nullopt if none

   for (int i = 0; i < fees.size(); i++) {

       if (fees[i] > 0.005) return std::make_pair(i, fees[i]);
   }

    return std::nullopt;
}

std::tuple<std::string, double> get_wallet_details() {
    // TODO: return a tuple of (wallet_name, balance)
    // Failed to fully understand how this was asked/ set

    return {"satoshi_wallet", 50.0};
}

std::string get_tx_status(const std::map<std::string, std::string>& tx_pool, const std::string& txid) {
    // TODO: return tx_pool[txid] if present, else "not found"

    for (const auto& [key, value] : tx_pool) {
        if (key == txid) return value;
    }

    return "not found";
}

std::string unpack_wallet_info(const std::tuple<std::string, double>& wallet_info) {
    // TODO: destructure into (name, balance) and return "Wallet <name> has balance: <balance> BTC"

    auto [name, balance] = wallet_info;

    return "Wallet "+ name + " has balance: " + std::to_string(balance).substr(0, 4) +" BTC";
}

long long calculate_sats(double btc) {
    // TODO: multiply btc by BTC_TO_SATS and return as integer
    return static_cast<long long>(btc * BTC_TO_SATS);
}

std::string generate_address(const std::string& prefix) {
    // TODO: append (32 - prefix.size()) random chars from [a-z0-9] to `prefix` and return it
    return "";
}

std::pair<bool, std::string> validate_block_height(int height) {
    // TODO: reject if negative; reject if > 800000; otherwise valid

    if (height < 0) {
        return {false, "Block height cannot be negative"};
    }

    if (height >= 0 && height <= 800000) {
        return {true, "Valid block height"};
    }

    return {false, "Block height seems unrealistic"};
}

std::pair<bool, std::string> validate_block_height(double height) {
    // TODO: a non-integer block height should always be rejected
    return {false, "Block height must be an integer"};
}

std::pair<bool, std::string> validate_block_height(const std::string& height) {
    // TODO: a string block height should always be rejected
    return {false, "Block height must be an integer"};
}

std::map<int, long long> halving_schedule(const std::vector<int>& blocks) {
    // TODO: base reward = 50 * BTC_TO_SATS sats, halve every 210_000 blocks
    //       return a map of {block_height: reward_in_sats}
    return {};
}

std::optional<Utxo> find_utxo_with_min_value(const std::vector<Utxo>& utxos, long long target) {
    // TODO: among utxos with value >= target, return the one with the smallest value
    //       (std::nullopt if none qualifies)
    return std::nullopt;
}

std::map<std::string, UtxoField> create_utxo(
    const std::string& txid,
    int vout,
    const std::map<std::string, UtxoField>& extras
) {
    // TODO: build a map with {"txid": txid, "vout": vout} merged with `extras`
    return {};
}
