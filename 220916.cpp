#include <iostream>
#include <string>

using namespace std;

struct SinhVien
{
    int maSV;
    string tenSV;
    string lop;
    float DiemTongKet;
    string HanhKiem;
};

struct node
{
    SinhVien data;
    node* left;
    node* right;
};

void KHOI_TAO(node* &root)
{
    root = nullptr;
}

node* TAO_NODE(SinhVien sv)
{
    node* NewNode = new node;
    NewNode->data = sv;
    NewNode->left = nullptr;
    NewNode->right = nullptr;
    return NewNode;
}

node* CHEN_NODE(node* root, SinhVien sv)
{
    if(root == nullptr)
    {
        return TAO_NODE(sv);
    }
    if(sv.maSV < root->data.maSV)
    {
        root->left = CHEN_NODE(root->left, sv);
    }
    else
        if(sv.maSV > root->data.maSV)
        {
            root->right = CHEN_NODE(root->right, sv);
        }
    return root;
}

node* TIM(node* root, int maSV)
{
    if(root == nullptr || root->data.maSV == maSV)
    {
        return root;
    }
    if(maSV < root->data.maSV)
    {
        return TIM(root->left, maSV);
    }
    return TIM(root->right, maSV);
}

void XUAT(SinhVien sv)
{
    cout<<"Ma sinh vien: "<<sv.maSV<<" | Ten: "<<sv.tenSV<<" | Lop: "<<sv.lop<<" | Diem tong ket: "<<sv.DiemTongKet<<" | Hanh kiem: "<<sv.HanhKiem<<endl;
}

void DUYET(node* root)
{
    if(root != nullptr)
    {
        DUYET(root->left);
        XUAT(root->data);
        DUYET(root->right);
    }
}

SinhVien NHAP()
{
    SinhVien sv;
    cout<<"Ma sinh vien: ";
    cin>>sv.maSV;
    cin.ignore();
    cout<<"Ten sinh vien:";
    getline(cin, sv.tenSV);
    cout<<"Lop: ";
    getline(cin, sv.lop);
    cout<<"Diem tong ket: ";
    cin>>sv.DiemTongKet;
    cin.ignore();
    cout<<"Hanh kiem: ";
    getline(cin, sv.HanhKiem);
    return sv;
}

int main()
{
    node* root;
    KHOI_TAO(root);

    int n;
    cout<<"Nhap so luong sinh vien: ";
    cin>>n;
    cout<<"--NHAP THONG TIN"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<"--Sinh vien "<<i+1<<":"<<endl;
        SinhVien sv = NHAP();
        root = CHEN_NODE(root, sv);
    }

    cout<<"--DANH SACH SINH VIEN"<<endl;
    if(root == nullptr)
    {
        cout<<"Danh sach trong."<<endl;
        return 0;
    }
    else
    {
        DUYET(root);
    }

    cout<<"--Nhap ma sinh vien can tim: ";
    int msv;
    cin>>msv;
    node* result = TIM(root, msv);
    if(result != nullptr)
    {
        XUAT(result->data);
    }
    else
    {
        cout<<"Khong co ma sinh vien nay."<<endl;
    }
}