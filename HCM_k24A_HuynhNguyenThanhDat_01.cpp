#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MAX_SIZE 100
bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// tim kiem nhi phan 
bool binary_search(int arr[], int size, int key) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == key) {
            return true;
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
}

// sap xep mang theo thu tu giam dan (Insertion Sort)
void Inertion_sort(int arr[],int size){
	for(int i=1;i<size;i++){
		int key=arr[i];
		int j=i-1;
		while(j>=0&&key<arr[j]){
		  arr [j+1]=arr[j];
		  j-=1; 
	} 
	arr[j+1]=key;
}
// Sap xep theo thu tu giam dan (Bubble Sort)
void bubble_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice;

    while (1) {
       printf("=========MENU=========\n");
	printf("1.nhap so phan tu va gia tri cho mang\n");
	printf("2.in ra cac gia tri phan tu trong mang\n");
	printf("3.dem so luong cac phan tu chan le trong mang\n");
	printf("4.tim gia tri lon thu 2 trong mang\n");
	printf("5.them mot phan tu vao dau mang\n");
	printf("6.xoa phan tu tai mot vi tri cu the\n");
	printf("7.sap xep mang theo thu tu giam dan\n");
	printf("8.cho nguoi dung nhap mot phan tu,tim kiem xem phan tu do co ton tai trong mang hay khong\n");
	printf("9.in ra toan bo so nguyen trong mang duoc binh phuong\n");
	printf("10.sap xep mang theo thu tu giam dan (Bubble sort)\n");
        printf("0. Thoát\n");
        printf("nhap lua chon cua ban (0-10): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("nhap so phan tu trong mang: ");
                scanf("%d", &size);
                printf("nhap cac gia tri cho mang:\n");
                for (int i = 0; i < size; i++) {
                    printf("arr[%d] = ", i);
                    scanf("%d", &arr[i]);
                }
                break;
            }
            case 2: {
                printf("cac phan tu trong mang la:\n");
                for (int i = 0; i < size; i++) {
                    printf("arr[%d] = %d\n", i, arr[i]);
                }
                break;
            }
            case 3: {
                int sochan = 0, sole = 0;
                for (int i = 0; i < size; i++) {
                    if (arr[i] % 2 == 0) {
                        sochan++;
                    } else {
                        sole++;
                    }
                }
                printf("so luong so chan: %d\n", sochan);
                printf("so luong so le: %d\n", sole);
                break;
            }
            case 4: {
                if (size < 2) {
                    printf("mang co it nhat 2 phan tu lon thu 2 trong mang\n");
                } else {
                    int max1 = arr[0], max2 = arr[0];
                    for (int i = 1; i < size; i++) {
                        if (arr[i] > max1) {
                            max2 = max1;
                            max1 = arr[i];
                        } else if (arr[i] > max2 && arr[i] != max1) {
                            max2 = arr[i];
                        }
                    }
                    printf("gia tri lon thu hai trong mang la: %d\n", max2);
                }
                break;
            }
            case 5: {
                int value;
                printf("nhap gia tri phan tu moi: ");
                scanf("%d", &value);
                for (int i = size; i > 0; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[0] = value;
                size++;
                printf("mang sau khi them vao dau: ");
                for (int i = 0; i < size; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            }
            case 6: {
                int deleteindex;
                printf("nhap vi tri can xoa: ", size - 1);
                scanf("%d", &deleteindex);
                if (deleteindex >= 0 && deleteindex < size) {
                    for (int i = deleteindex; i < size - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    size--;
                    printf("mang sau khi duoc xoa tai phan tu vi tri %d: ", deleteindex);
                    for (int i = 0; i < size; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                } else {
                    printf("vi tri khong hop le \n");
                }
                break;
            }
            case 7: {
                insertion_sort(arr, size);
                printf("mang sau khi sap xep theo thu tu giam dan (Insertion sort): ");
                for (int i = 0; i < size; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            }
            case 8:
			bool binary_search(int arr[], int size, int key) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == key) {
            return true;
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
} {
                int value;
                printf("nhap phan tu can tim kiem: ");
                scanf("%d", &value);
                if (binary_search(arr, size, value)) {
                    printf("Phan tu %d có trong mang.\n", value);
                } else {
                    printf("Phan tu %d khong co trong mang.\n", value);
                }
                break;
            }
            case 9: {
                int prime_found = 0;
                printf("cac so nguyen to trong mang du?c binh phuong: ");
                for (int i = 0; i < size; i++) {
                    if (is_prime(arr[i])) {
                        printf("%d ", arr[i] * arr[i]);
                        prime_found = 1;
                    }
                }
                if (!prime_found) {
                    printf("khong co so nguyen to nao trong mang.\n");
                }
                printf("\n");
                break;
            }
            case 10: {
                bubble_sort(arr, size);
                printf("mang sau khi sap xep theo thu tu giam dan (Bubble sort): ");
                for (int i = 0; i < size; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            }
            case 0: {
                printf("Thoat chuong trinh.\n");
                return 0;
            }
            default:
                printf("lua chon khong hop le vui long chon lai.\n");
        }
    }
}

