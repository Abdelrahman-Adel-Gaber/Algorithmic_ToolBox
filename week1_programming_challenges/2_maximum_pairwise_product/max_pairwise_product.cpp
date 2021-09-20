#include <iostream>
#include <vector>
#include <algorithm>

 long long  MaxPairwiseProduct(const std::vector<int>& numbers) {
   long long max_product = 0;
    int n = numbers.size();
    int max_num1_index=-1;
    int max_num2_index=-1;


    for (int first = 0; first < n; ++first) {
        if(numbers[first]>numbers[max_num1_index])
        {
            max_num1_index=first;
        }

         }

    for (int first = 0; first < n; ++first) {
        if((numbers[first]>numbers[max_num2_index])&&(max_num1_index != first))
        {
            max_num2_index=first;
        }
      }
      

 max_product = (long long)numbers[max_num1_index]*numbers[max_num2_index] ;
    return max_product;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
