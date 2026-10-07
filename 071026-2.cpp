#include <iostream>
#include <string>

using namespace std;

struct NhanVien
{
    string ma;
    string ten;
    string ngaySinh;
    double luong;
};

void NHAP(NhanVien a[], int n)
{
    for (int i=0; i<n; i++)
    {
        cout<<"--- Nhap thong tin nhan vien thu "<< i + 1<<endl;
        cout<<"Ma nhan vien: ";
        cin>>a[i].ma;
        cin.ignore(); 
        cout<<"Ho ten: ";
        getline(cin, a[i].ten);
        cout<<"Ngay sinh : ";
        getline(cin, a[i].ngaySinh);
        cout<<"Luong (trieu dong): ";
        cin>>a[i].luong;
    }
}

void XUAT(NhanVien a[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<"Ma NV: "<<a[i].ma<< " | Ho ten: "<<a[i].ten<<" | Ngay sinh: "<<a[i].ngaySinh<<" | Luong: "<<a[i].luong<<endl;
    }
}

void BUBB_SORT(NhanVien a[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(a[j].luong> a[j+1].luong)
            {
                NhanVien temp = a[j];
                a[j]=a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void BINA_SEARCH(NhanVien a[], int n, double X)
{
    int left = 0, right = n-1;
    int found = -1;

    while(left <= right)
    {
        int mid = left + (right - left)/2;
        if(a[mid].luong == X)
        {
            found = mid;
            break;
        }
        if(a[mid].luong < X)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

cout<<"--Cac nhan vien co luong bang "<< X<<endl;
        
    if (found != -1)
    {
        int i = found;
        while(i >= 0 && a[i].luong == X)
            i--;
        int start = i+1;

        int j = found;
        while(j<n&&a[j].luong == X)
            j++;
        int end = j-1;

        for (int k = start; k <= end; k++)
        {
            cout<<"Ma NV: "<<a[i].ma<< " | Ho ten: "<<a[i].ten<<" | Ngay sinh: "<<a[i].ngaySinh<<" | Luong: "<<a[i].luong<<endl;
        }
    }
    else
    {
        cout << "Khong tim thay."<<endl;
    }
}

int main()
{
    
    cout<<"--Nhap so luong nhan vien: ";
    int n;
    cin >> n;


    NhanVien* a = new NhanVien[n];

    NHAP(a, n);
    cout << "\n--Danh sach nhan vien"<<endl;
    XUAT(a, n);

    
    cout << "\n--Danh sach sau khi sap xep tang dan theo luong"<<endl;
    BUBB_SORT(a, n);
    XUAT(a, n);

    
    cout<<"Nhap luong can tim: ";
    double X;
    cin >> X;
    BINA_SEARCH(a, n, X);
}