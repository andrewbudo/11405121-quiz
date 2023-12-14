#include <iostream>
#include <string>
using namespace std;

// Функция для подсчёта суммы цифр в числе
int digitSum(int number) {
  int sum = 0;
  while (number > 0) {
    sum += number % 10;
    number /= 10;
  }
  return sum;
}

// Функция для генерации всех возможных комбинаций номеров билетов длины N
void generateTickets(int N, int currentNumber, int sum, int &count) {
  if (N == 0) {
    if (sum == 0) {
      count++;
    }
    return;
  }

  // Генерируем новые номера билетов, добавляя цифры от 0 до 9
  for (int i = 0; i <= 9; ++i) {
    int newNumber = currentNumber * 10 + i;
    generateTickets(N - 1, newNumber, sum + (N % 2 ? i : -i), count);
  }
}

int main() {
  int N;
  cin >> N;

  int count = 0;
  int initialNumber = 0; // Начальное число - пустое
  generateTickets(N, initialNumber, 0, count);

  cout << count << endl;

  return 0;
}
