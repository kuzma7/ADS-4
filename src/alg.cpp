// Copyright 2021 NNTU-CS
int SearchBin(int* arr, int left, int right, int value) {
    int anyu = 0;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (arr[middle] == value) {
            anyu++;
            int temp = middle - 1;
            while (temp >= left && arr[temp] == value) {
                anyu++;
                temp--;
            }
            temp = middle + 1;
            while (temp <= right && arr[temp] == value) {
                anyu++;
                temp++;
            }
            break;
        }
        if (arr[middle] < value) {
            left = middle + 1;
        }
        if (arr[middle] > value) {
            right = middle - 1;
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
