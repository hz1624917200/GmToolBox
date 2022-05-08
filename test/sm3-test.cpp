#pragma once
#include <algorithm>
#include <array>
#include <cassert>
#include <cstdint>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <ranges>
#include <string>
#include <tuple>
#include <unordered_map>
#include <utility>
#include "sm3.h"

#define val const auto
#define var auto
using byte = uint8_t;
using std::array;
using std::make_shared;
using std::map;
using std::move;
using std::pair;
using std::shared_ptr;
using std::string;
using std::tuple;
using std::unordered_map;

unordered_map<string, byte> map_xff2byte;
unordered_map<byte, string> map_byte2xff;
unordered_map<string, string> table;
// map<string, byte> map_xff2byte;
// map<byte, string> map_byte2xff;
// map<string, string> table;

int _ = []() {
    static constexpr auto alphabet = std::to_array<const char>("0123456789abcdef");
	
    for (var i = 0; i < alphabet.size() - 1; ++i) {
        for (var j = 0; j < alphabet.size() - 1; ++j) {
            byte tmp_byte = i * 16 + j;
            string tmp_str{alphabet[i], alphabet[j]};
            map_byte2xff[tmp_byte] = tmp_str;
            map_xff2byte[tmp_str] = tmp_byte;
        }
    }
    var test1 = string{"616263"};
    var ans1 =
        string{"66c7f0f4 62eeedd9 d1f2d46b dc10e4e2 4167c487 5cf2f7a2 297da02b 8f4ba8e0"};
    var test2 = string{
        "61626364 61626364 61626364 61626364 61626364 61626364 61626364 61626364 "
        "61626364 61626364 61626364 61626364 61626364 61626364 61626364 61626364 "};
    var ans2 =
        string{"debe9ff9 2275b8a1 38604889 c18e5a4d 6fdb70e5 387e5765 293dcba3 9c0c5732"};
    for (auto& str : {std::ref(test1), std::ref(test2), std::ref(ans1), std::ref(ans2)})
        str.get().erase(remove_if(str.get().begin(), str.get().end(), isspace),
                        str.get().end());
    table[move(test1)] = move(ans1);
    table[move(test2)] = move(ans2);
    return 0;
}();

decltype(auto) xffstr2byte(const string& s) {
    assert(s.size() % 2 == 0);
    size_t n = s.size() / 2;
    auto arr = make_shared<byte[]>(n);
    for (auto i = 0; i < n; ++i) {
        if (i >= 7)
            arr[i] = map_xff2byte[string{s[2 * i], s[2 * i + 1]}];
        std::cout << i << ' ' << std::endl;
    }
    return std::make_tuple(move(arr), move(n));
}
decltype(auto) byte2xffstr(shared_ptr<byte[]> pb) {
    string ans;
    for (val& x :
         std::views::iota(0, SM3_DIGEST_SIZE) |
             std::views::transform([&pb](size_t i) { return map_byte2xff[pb[i]]; })) {
        ans += x;
    }
    return ans;
}
decltype(auto) sm3proxy(tuple<shared_ptr<byte[]>, size_t>&& t) {
    auto pdgst = make_shared<byte[SM3_DIGEST_SIZE]>();
    sm3_digest(std::get<0>(t).get(), std::get<1>(t), pdgst.get());
    return pdgst;
}
int main() {
    // auto pdgst = make_shared<byte[SM3_DIGEST_SIZE]>();
    // for (val & [ k, v ] : m) {
    //     std::cout << k << ", " << static_cast<int>(v) << std::endl;
    // }
    for (val & [ k, v ] : table) {
        auto tmp = byte2xffstr(sm3proxy(xffstr2byte(k)));
        std::cout << static_cast<bool>(tmp == v) << '\t' << k << std::endl
                  << v << std::endl
                  << tmp << std::endl
                  << std::endl;
    }

    return 0;
}