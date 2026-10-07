#include <iostream>
#include <string>

using namespace std;

struct Khachhang
{
    int ma;
    string ten;
    string sdt;
    double tien;
};

void NHAP(Khachhang a[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<"--Khach hang thu "<<i+1<<":"<<endl;
        cout<<"Ma khach hang: ";
        cin>>a[i].ma;
        cin.ignore();
        cout<<"Ten khach hang: ";
        getline(cin, a[i].ten);
        cout<<"So dien thoai: ";
        getline(cin, a[i].sdt);
        cout<<"Tong tien thanh toan: ";
        cin>>a[i].tien;
    }
}

void XUAT(Khachhang a[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<"Ma khach hang: "<<a[i].ma<<" | Ten khach hang: "<<a[i].ten<<" | So dien thoai: "<<a[i].sdt<<" | Tong tien: "<<a[i].tien<<endl;
    }
}

void INSERTION_SORT(Khachhang a[], int n)
{
    for(int i=1; i<n; i++)
    {
        Khachhang key = a[i];
        int j=i-1;
        while (j>=0&&a[j].tien > key.tien)
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1] = key;
    }
}

void BINARY_SEARCH(Khachhang a[], int n, double x)
{
    int left = 0, right = n-1;
    int found = -1;

    while (left <= right)
    {
        int mid = left + (right - left)/2;
        if(a[mid].tien == x)
        {
            found = mid;
            break;
        }
        if(a[mid].tien < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    
    cout<<"--Khach hang co tong tien "<<x<<":"<<endl;
    if(found != -1)
    {
        int i = found;
        while (i>=0&&a[i].tien == x)
        {
            i--;
        }
        int start = i+1;

        int j = found;
        while (j<n&&a[j].tien == x)
        {
            j++;
        }
        int end = j-1;

        for(int k = start; k <= end; k++)
        {
            cout<<"Ma khach hang: "<<a[i].ma<<" | Ten khach hang: "<<a[i].ten<<" | So dien thoai: "<<a[i].sdt<<" | Tong tien: "<<a[i].tien<<endl;
        }
        
    }
    else
    {
        cout<<"Khong tim thay."<<endl;
    }
}

int main()
{
    int n;
    cout<<"--Nhap so luong khach: ";
    cin>>n;
    cin.ignore();
    Khachhang* a = new Khachhang[n];

    NHAP(a, n);
    cout<<"--Danh sach khach hang:"<<endl;
    XUAT(a, n);

    cout<<"--Danh sach tang dan theo tong tien: "<<endl;
    INSERTION_SORT(a, n);
    XUAT(a, n);

    cout<<"--Nhap so tien can timf: ";
    double x;
    cin>>x;
    cin.ignore();
    BINARY_SEARCH(a, n, x);
}