#include <bits/stdc++.h>

int countDivisors(int num) {
  int count = 0;
  for (int i = 1; i * i <= num; ++i) {
    if (num % i == 0) {
      if (i * i == num) {
        ++count;
      } else {
        count += 2;
      }
    }
  }
  return count;
}

int main() {
  std::map<int, int> minDivisors;

  for (int i = 1; i <= 5000000; ++i) {
    int divisors = countDivisors(i);

    if ((minDivisors.find(divisors) == minDivisors.end() ||
        i < minDivisors[divisors]) && divisors <=100){
        minDivisors[divisors] = i;
    }
  }

 //Hasta 5000000
 /*
 N├║mero: 1, M├¡nimo n├║mero de divisores: 1
N├║mero: 2, M├¡nimo n├║mero de divisores: 2
N├║mero: 4, M├¡nimo n├║mero de divisores: 3
N├║mero: 6, M├¡nimo n├║mero de divisores: 4
N├║mero: 16, M├¡nimo n├║mero de divisores: 5
N├║mero: 12, M├¡nimo n├║mero de divisores: 6
N├║mero: 64, M├¡nimo n├║mero de divisores: 7
N├║mero: 24, M├¡nimo n├║mero de divisores: 8
N├║mero: 36, M├¡nimo n├║mero de divisores: 9
N├║mero: 48, M├¡nimo n├║mero de divisores: 10
N├║mero: 1024, M├¡nimo n├║mero de divisores: 11
N├║mero: 60, M├¡nimo n├║mero de divisores: 12
N├║mero: 4096, M├¡nimo n├║mero de divisores: 13
N├║mero: 192, M├¡nimo n├║mero de divisores: 14
N├║mero: 144, M├¡nimo n├║mero de divisores: 15
N├║mero: 120, M├¡nimo n├║mero de divisores: 16
N├║mero: 65536, M├¡nimo n├║mero de divisores: 17
N├║mero: 180, M├¡nimo n├║mero de divisores: 18
N├║mero: 262144, M├¡nimo n├║mero de divisores: 19
N├║mero: 240, M├¡nimo n├║mero de divisores: 20
N├║mero: 576, M├¡nimo n├║mero de divisores: 21
N├║mero: 3072, M├¡nimo n├║mero de divisores: 22
N├║mero: 4194304, M├¡nimo n├║mero de divisores: 23
N├║mero: 360, M├¡nimo n├║mero de divisores: 24
N├║mero: 1296, M├¡nimo n├║mero de divisores: 25
N├║mero: 12288, M├¡nimo n├║mero de divisores: 26
N├║mero: 900, M├¡nimo n├║mero de divisores: 27
N├║mero: 960, M├¡nimo n├║mero de divisores: 28
N├║mero: 720, M├¡nimo n├║mero de divisores: 30
N├║mero: 840, M├¡nimo n├║mero de divisores: 32
N├║mero: 9216, M├¡nimo n├║mero de divisores: 33
N├║mero: 196608, M├¡nimo n├║mero de divisores: 34
N├║mero: 5184, M├¡nimo n├║mero de divisores: 35
N├║mero: 1260, M├¡nimo n├║mero de divisores: 36
N├║mero: 786432, M├¡nimo n├║mero de divisores: 38
N├║mero: 36864, M├¡nimo n├║mero de divisores: 39
N├║mero: 1680, M├¡nimo n├║mero de divisores: 40
N├║mero: 2880, M├¡nimo n├║mero de divisores: 42
N├║mero: 15360, M├¡nimo n├║mero de divisores: 44
N├║mero: 3600, M├¡nimo n├║mero de divisores: 45
N├║mero: 2520, M├¡nimo n├║mero de divisores: 48
N├║mero: 46656, M├¡nimo n├║mero de divisores: 49
N├║mero: 6480, M├¡nimo n├║mero de divisores: 50
N├║mero: 589824, M├¡nimo n├║mero de divisores: 51
N├║mero: 61440, M├¡nimo n├║mero de divisores: 52
N├║mero: 6300, M├¡nimo n├║mero de divisores: 54
N├║mero: 82944, M├¡nimo n├║mero de divisores: 55
N├║mero: 6720, M├¡nimo n├║mero de divisores: 56
N├║mero: 2359296, M├¡nimo n├║mero de divisores: 57
N├║mero: 5040, M├¡nimo n├║mero de divisores: 60
N├║mero: 14400, M├¡nimo n├║mero de divisores: 63
N├║mero: 7560, M├¡nimo n├║mero de divisores: 64
N├║mero: 331776, M├¡nimo n├║mero de divisores: 65
N├║mero: 46080, M├¡nimo n├║mero de divisores: 66
N├║mero: 983040, M├¡nimo n├║mero de divisores: 68
N├║mero: 25920, M├¡nimo n├║mero de divisores: 70
N├║mero: 10080, M├¡nimo n├║mero de divisores: 72
N├║mero: 32400, M├¡nimo n├║mero de divisores: 75
N├║mero: 3932160, M├¡nimo n├║mero de divisores: 76
N├║mero: 746496, M├¡nimo n├║mero de divisores: 77
N├║mero: 184320, M├¡nimo n├║mero de divisores: 78
N├║mero: 15120, M├¡nimo n├║mero de divisores: 80
N├║mero: 44100, M├¡nimo n├║mero de divisores: 81
N├║mero: 20160, M├¡nimo n├║mero de divisores: 84
N├║mero: 107520, M├¡nimo n├║mero de divisores: 88
N├║mero: 25200, M├¡nimo n├║mero de divisores: 90
N├║mero: 2985984, M├¡nimo n├║mero de divisores: 91
N├║mero: 27720, M├¡nimo n├║mero de divisores: 96
N├║mero: 233280, M├¡nimo n├║mero de divisores: 98
N├║mero: 230400, M├¡nimo n├║mero de divisores: 99
N├║mero: 45360, M├¡nimo n├║mero de divisores: 100
 */
 /*{1,2,4,6,16,12,64,24,36,48,1024,60,4096,
 192,144,120,65536,180,262144,240,576,3072,
 4194304,360,1296,12288,900,960,,720,,840,
 9216,196608,5184,1260,,786432,36864,1680,,
 2880,,15360,3600,,,2520,46656,6480,589824,
 61440,,6300,82944,6720,2359296,,,5040,,,14400,
 7560,331776,46080,,983040,,25920,,10080,,,32400,
 3932160,746496,184320,,15120,44100,,,20160,,,,
 107520,,25200,2985984,,,,,27720,,233280,230400,45360,} */

 //i = 5000001; i <= 10000000; Ninguno adicional

  for (const auto &pair : minDivisors) {
    std::cout <<pair.first
              <<"-"
              <<pair.second<< "\n";
  }
  std::cout<<"{";
  for(int i=1;i<=100;i++){
    if (minDivisors.find(i) != minDivisors.end())
        std::cout<<minDivisors[i]<<",";
    else std::cout<<",";
  }
  std::cout<<"}";
  return 0;
}
