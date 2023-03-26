// Copyright 2021 NNTU-CS
int SearchBin(int* arr, int left, int right, int value) {
    int anyu = 0;
    int middle = 0;
    int temp = 0;
    while (right - left > 1) {
        middle = (left + right) / 2;
        if (arr[middle] == value) {
            anyu = anyu + 1;
            temp = middle + 1;
            while (arr[temp] == value && temp < right) {
                anyu = anyu + 1;
                temp = temp + 1;
            }
            temp = middle - 1;
            while (arr[temp] == value && temp > left) {
                anyu = anyu + 1;
                temp = temp - 1;
            }
            break;
        }
        if (arr[middle] < value) {
            left = middle;
        }
        if (arr[middle] > value) {
            right = middle;
        }
    }
    return anyu;
}
int countPairs1(int* arr, int len, int value) {
    int anyu = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                anyu = anyu + 1;
            }
        }
    }
    return anyu;
}
int countPairs2(int* arr, int len, int value) {
    int anyu = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = len - 1; i < j; --j) {
            if (arr[i] + arr[j] == value) {
                anyu = anyu + 1;
            }
        }
    }
    return anyu;
}
int countPairs3(int* arr, int len, int value) {
    int anyu = 0;
    int value1 = 0;
    for (int i = 0; i < len - 1; ++i) {
        value1 = value - arr[i];
        anyu = anyu + SearchBin(arr, i, len, value1);
    }
    return anyu;
}
