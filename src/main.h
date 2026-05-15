#pragma once

#include <cstddef>
#include <cstdint>
#include <map>
#include <optional>
#include <string>
#include <tuple>
#include <utility>
#include <variant>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <sstream>

// ---- Name assignment (variables and constants) ------------------------------

// TODO: assign the current Bitcoin mining reward (in BTC)
inline double MINING_REWARD = 0.0;

// TODO: assign the current block height as an integer
inline int current_block_height = 0;

// TODO: assign the number of satoshis in one Bitcoin
inline long long BTC_TO_SATS = 0;

// ---- Supporting types -------------------------------------------------------

struct Utxo {
    std::string txid;
    long long value = 0;

    bool operator==(const Utxo& other) const {
        return txid == other.txid && value == other.value;
    }
};

struct Wallet {
    std::string address;

    bool operator==(const Wallet& other) const {
        return address == other.address;
    }
};

using UtxoField = std::variant<std::string, long long, int>;

// ---- Function declarations --------------------------------------------------

double calculate_total_reward(int blocks_mined);

bool is_valid_tx_fee(double fee);

bool is_large_balance(double balance);

std::string tx_priority(int size_bytes, double fee_btc);

bool is_mainnet(std::string network);

bool is_in_range(double value);

bool is_same_wallet(const Wallet& w1, const Wallet& w2);

std::string normalize_address(std::string address);

std::vector<int> add_utxo(std::vector<int> utxos, int new_utxo);

std::optional<std::pair<std::size_t, double>> find_high_fee(const std::vector<double>& fees);

std::tuple<std::string, double> get_wallet_details();

std::string get_tx_status(const std::map<std::string, std::string>& tx_pool, const std::string& txid);

std::string unpack_wallet_info(const std::tuple<std::string, double>& wallet_info);

long long calculate_sats(double btc);

std::string generate_address(const std::string& prefix = "bc1q");

// Mirrors validate_block_height(height: Union[int, float, str]) via overloading.
std::pair<bool, std::string> validate_block_height(int height);
std::pair<bool, std::string> validate_block_height(double height);
std::pair<bool, std::string> validate_block_height(const std::string& height);

std::map<int, long long> halving_schedule(const std::vector<int>& blocks);

std::optional<Utxo> find_utxo_with_min_value(const std::vector<Utxo>& utxos, long long target);

// C++ has no native **kwargs; model extras as a map of name -> variant value.
std::map<std::string, UtxoField> create_utxo(
    const std::string& txid,
    int vout,
    const std::map<std::string, UtxoField>& extras = {}
);
