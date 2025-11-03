#include <iostream>
using namespace std;

int main() {
    const int MAX_SIZE = 10;
    int arr[MAX_SIZE];
    int n; 
    int choice;

    do {
        cout << "Nhap so luong phan tu cua mang (toi da 10): ";
        cin >> n;
        if (n < 0 || n > MAX_SIZE)
            cout << "So luong khong hop le, vui long nhap lai!\n";
    } while (n < 0 || n > MAX_SIZE);

    
    for (int i = 0; i < n; i++) {
        cout << "Nhap phan tu thu " << i << ": ";
        cin >> arr[i];
    }
    
	do {
        cout << "\n- MENU -\n";
        cout << "1. Them mot phan tu vao mang\n";
        cout << "2. Xoa mot phan tu tai vi tri bat ki\n";
        cout << "3. Tim kiem mot gia tri trong mang\n";
        cout << "4. Sap xep mang (tang dan hoac giam dan)\n";
        cout << "5. Thoat\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;
        
		switch (choice) {
            case 1: {
                if (n >= MAX_SIZE) {
                    cout << "Mang da day, khong the them!\n";
                } else {
                    int value;
                    cout << "Nhap gia tri can them: ";
                    cin >> value;
                    arr[n] = value;
                    n++;
                    cout << "Da them thanh cong!\n";
                }
                break;
            }
            
			case 2: {
                int pos;
                cout << "Nhap vi tri muon xoa (0 -> " << n-1 << "): ";
                cin >> pos;
                if (pos < 0 || pos >= n) {
                    cout << "Vi tri khong hop le!\n";
                } else {
                    for (int i = pos; i < n - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    n--;
                    cout << "Da xoa thanh cong!\n";
                }
                break;
            }

            case 3: {
                int x;
                bool found = false;
                cout << "Nhap gia tri can tim: ";
                cin >> x;
                for (int i = 0; i < n; i++) {
                    if (arr[i] == x) {
                        cout << "Gia tri " << x << " ton tai o vi tri " << i << endl;
                        found = true;
                    }
                }
                if (!found)
                    cout << "Khong ton tai gia tri nay trong mang\n";
                break;
            }

            case 4: {
                int type;
                cout << "1. Sap xep tang dan\n";
                cout << "2. Sap xep giam dan\n";
                cout << "Nhap lua chon cua ban: ";
                cin >> type;

                for (int i = 0; i < n - 1; i++) {
                    for (int j = i + 1; j < n; j++) {
                        if ((type == 1 && arr[i] > arr[j]) ||
                            (type == 2 && arr[i] < arr[j])) {
                            int temp = arr[i];
                            arr[i] = arr[j];
                            arr[j] = temp;
                        }
                    }
                }

                cout << "Mang sau khi sap xep: ";
                for (int i = 0; i < n; i++)
                    cout << arr[i] << " ";
                cout << endl;
                break;
            }

            case 5:
                cout << "Thoat chuong trinh..\n";
                break;

            default:
                cout << "Lua chon cua ban khong hop le!\n";
        }

        cout << "Mang hien tai: ";
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;

    } while (choice != 5);

    return 0;
}

