// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i+1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}

int countPairs2(int* arr, int len, int value) {
    int count = 0;
    int i = 0;
    int j = len - 1;
    while (i < j) {
        int sum = arr[i] + arr[j];
        if (sum == value) {
            count++;
            i++;
            j--;
        }
        else if (sum > value) {
            j--;
        }
        else {
            i++;
        }
    }
    return count;
}

int countPairs3(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        int diff = value - arr[i];
        int low = i + 1;
        int high = len - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] == diff) {
                if (arr[i] != arr[mid]) {
                    count++;
                }
                break;
            }
            else if (arr[mid] < diff) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
    }
    return count;
}
