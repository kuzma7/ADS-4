// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int left = 0;
    int right = len - 1;
    while (left < right) {
        if (arr[left] + arr[right] == value) {
            count++;
            left++;
            right--;
        } else if (arr[left] + arr[right] < value) {
            left++;
        } else {
            right--;
        }
    }
    return count;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        int left = i + 1;
        int right = len - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] + arr[i] == value) {
                count++;
                break;
            } else if (arr[mid] + arr[i] < value) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return count;
}
