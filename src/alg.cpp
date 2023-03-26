// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
    int detect = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                detect += 1;
            }
        }
    }
    return detect;
}
int countPairs2(int* arr, int len, int value) {
    int detect = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = len - 1; i < j; j--) {
            if (arr[i] + arr[j] == value) {
                detect += 1;
            }
        }
    }
    return detect;
}
int countPairs3(int* arr, int len, int value) {
    int detect = 0;
    for (int i = 0; i < len - 1; i++) {
        int l = i, r = len;
        while (l < r - 1) {
            int val = (l + r) / 2;
            if (arr[i] + arr[val] == value) {
                detect += 1;
                int NewVal = val + 1;
                while (arr[i] + arr[NewVal] == value && NewVal < r) {
                    detect += 1;
                    NewVal += 1;
                }
                NewVal = val - 1;
                while (arr[i] + arr[NewVal] == value && NewVal > l) {
                    detect += 1;
                    NewVal -= 1;
                }
                break;
            }
            if (arr[i] + arr[val] > value) {
                r = val;
            } else {
                l = val;
            }
        }
    }
    return detect;
}
