// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
    return 0;
    int val = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value)
                val += 1;
        }
    }
    return val;
}
int countPairs2(int* arr, int len, int value) {
    return 0;
    int val = 0;
    for (int i = 0; i < len; i++) {
        for (int j = len; i < j; j--) {
            if (arr[i] + arr[j] == value)
                val += 1;
        }
    }
    return val;
}
int countPairs3(int* arr, int len, int value) {
    return 0;
    int val = 0;
    for (int i = 0; i < len; i++) {
        int left = 0, right = len;
        while (1 < right - left) {
            int tem = (left + right) / 2;
            if (arr[i] + arr[tem] == value) {
                val++;
                int reg = tem + 1;
                while (arr[i] + arr[reg] == value && reg < right) {
                    val++;
                    reg++;
                }
                reg = tem - 1;
                while (arr[i] + arr[reg] == value && reg > left) {
                    val++;
                    reg--;
                }
                break;
            }
            if (arr[i] + arr[tem] > value) {
                right = tem;
            } else {
                left = tem;
            }
        }
    }
    return val;
}
