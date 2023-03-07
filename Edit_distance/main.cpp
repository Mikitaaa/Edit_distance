#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

size_t get_levenshtein_distance(const std::string &str1, const std::string &str2) {
    size_t size1 = str1.size()+1;
    size_t size2 = str2.size()+1;
    size_t edit_dist = 0;
    if (str1.empty() || str2.empty()) {
        return size1 + size2;
    }

    std::vector<size_t> curr(size1);
    std::vector<size_t> prev(size1);
    
    for(int z = 0; z<size1; ++z) prev[z]=z;
    
    for (size_t i = 1; i<size2; ++i) {
        curr[0] = i;
        for (size_t j = 1; j<size1; ++j) {
            size_t insert_distance = curr[j-1]+1;
            size_t delete_distance = prev[j]+1;
            size_t match_distance = prev[j-1] + (str1[j-1] != str2[i-1]);
            curr[j] = std::min({insert_distance, delete_distance, match_distance});
        }
        edit_dist = curr[size1-1];
        std::copy(curr.begin(), curr.end(), prev.begin());
    }
    
    return edit_dist;
}

int main(void) {
  std::string str1;
  std::string str2;

  std::cin >> str1 >> str2;

  std::cout << get_levenshtein_distance(str1, str2) << std::endl;
}
