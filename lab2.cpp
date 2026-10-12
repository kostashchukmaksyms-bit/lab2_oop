#include <iostream>
#include <limits>

// 1. ШАБЛОН ФУНКЦІЇ: інвертує масив будь-яких типів (int, double)
template <typename T>
void reverseArray(T arr[], int size) {
    for (int i = 0; i < size / 2; ++i) {
        T temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

// Допоміжна функція: розвертає ділянку символьного масиву
void reverseSubstr(char* str, int start, int end) {
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

// 2. ПЕРЕЗАВАНТАЖЕНА ФУНКЦІЯ: переставляє слова у реченні (char*)
void reverseArray(char* str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }

    reverseSubstr(str, 0, len - 1);

    int start = 0;
    for (int i = 0; i <= len; ++i) {
        if (str[i] == ' ' || str[i] == '\0') {
            reverseSubstr(str, start, i - 1);
            start = i + 1;
        }
    }
}

// Перевірка розміру масиву (розмір обов'язково має бути > 0 та не більше maxLimit)
int readArraySize(int maxLimit) {
    int size;
    while (true) {
        if (std::cin >> size) {
            if (std::cin.peek() == '.' || std::cin.peek() == ',') {
                std::cout << "Помилка! Розмір має бути цілим числом. Введіть від 1 до " << maxLimit << ": ";
            } else if (size <= 0 || size > maxLimit) {
                std::cout << "Помилка! Розмір масиву має бути від 1 до " << maxLimit << ": ";
            } else {
                return size;
            }
        } else {
            std::cout << "Помилка вводу! Введіть розмір від 1 до " << maxLimit << ": ";
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

// Введення БУДЬ-ЯКОГО цілого числа (дозволено від'ємні, 0 та додатні)
int readAnyInt() {
    int val;
    while (true) {
        if (std::cin >> val) {
            // Перевіряємо, щоб після числа не було дробової крапки чи коми
            if (std::cin.peek() == '.' || std::cin.peek() == ',') {
                std::cout << "Помилка! Введено дробове число. Введіть ціле число (можна 0 та від'ємні): ";
            } else {
                return val; // Підходить будь-яке ціле число
            }
        } else {
            std::cout << "Помилка вводу! Введіть ціле число: ";
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

// Введення БУДЬ-ЯКОГО числа для елементів double (дозволено від'ємні, 0, дробові)
double readAnyDouble() {
    double val;
    while (true) {
        if (std::cin >> val) {
            return val;
        } else {
            std::cout << "Помилка вводу! Введіть число: ";
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int main() {
    const int MAX_SIZE = 10; // Максимально дозволений розмір масиву

    // --- 1. РОБОТА З МАСИВОМ INT ---
    std::cout << "=== 1. Масив int ===\n";
    std::cout << "Введіть розмір масиву int (1-" << MAX_SIZE << "): ";
    int intSize = readArraySize(MAX_SIZE);

    int* intArr = new int[intSize];
    for (int i = 0; i < intSize; ++i) {
        std::cout << "Введіть елемент [" << i << "]: ";
        intArr[i] = readAnyInt();
    }

    reverseArray(intArr, intSize);

    std::cout << "Інвертований масив int: ";
    for (int i = 0; i < intSize; ++i) {
        std::cout << intArr[i] << " ";
    }
    std::cout << "\n\n";
    delete[] intArr;

    // --- 2. РОБОТА З МАСИВОМ DOUBLE ---
    std::cout << "=== 2. Масив double ===\n";
    std::cout << "Введіть розмір масиву double (1-" << MAX_SIZE << "): ";
    int doubleSize = readArraySize(MAX_SIZE);

    double* doubleArr = new double[doubleSize];
    for (int i = 0; i < doubleSize; ++i) {
        std::cout << "Введіть елемент [" << i << "]: ";
        doubleArr[i] = readAnyDouble();
    }

    reverseArray(doubleArr, doubleSize);

    std::cout << "Інвертований масив double: ";
    for (int i = 0; i < doubleSize; ++i) {
        std::cout << doubleArr[i] << " ";
    }
    std::cout << "\n\n";
    delete[] doubleArr;

    // --- 3. РОБОТА З РЯДКОМ (CHAR*) ---
    std::cout << "=== 3. Речення (char*) ===\n";
    std::cout << "Введіть речення: ";
    std::cin.get(); // Очищення залишку символу \n

    char sentence[256];
    std::cin.getline(sentence, 256);

    reverseArray(sentence);

    std::cout << "Речення зі зворотним порядком слів: " << sentence << "\n";

    return 0;
}