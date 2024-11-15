#pragma once
#include "LinkList.h"


class Book {        //包含书籍ID、书名、作者、出版年份、副本数量
    string bookID;
    string title;
    string author;
    int year;
    int copies;

public:
    // 构造函数
    Book(string BookID="0000", string Title="NoTitle", string Author="NoAuthor", int Year=1900, int Copies=0)
        : bookID(BookID), title(Title), author(Author), year(Year), copies(Copies) {}


    bool borrowBook() {
        if (copies > 0) {
            copies--;
            return true; // 借书成功
        }
        return false; // 副本不足，借书失败
    }
    const string& getTitle() const {
        return title;
    }

    void addBook() {
        copies++;
    }
    const int& getCopies()
    {
        return copies;
    }


    friend ostream & operator<<(ostream &out, const Book &b) { 
        // 设置每个字段的列宽，使用left和right确保对齐，并在字段之间加入空格分隔
        out << left  << setw(20) << b.bookID         // 书籍ID左对齐，占20个字符宽度
            << left  << setw(30) << b.title          // 书名左对齐，占30个字符宽度
            << left  << setw(30) << b.author         // 作者左对齐，占30个字符宽度
            << right << setw(6)  << b.year           // 年份右对齐，占6个字符宽度
            << right << setw(4)  << b.copies  ;       // 副本数量右对齐，占4个字符宽度
                                         // 每个输出记录后换行
        return out;
    }




    friend istream & operator>>(istream &in, Book &b) {//cout<<"请输入数据域数据(ISBNTab书名Tab作者Tab出版年份Tab副本数量换行): "
        in >> b.bookID >> b.title >> b.author >> b.year >> b.copies;
        return in;
    }
    
    


   
	
};
class BorrowRecord;


class User {
    string userID;
    string name;
    LinkList<BorrowRecord> borrowedBooks;
    
public:
    LinkList<string>  unreturnedbooks;

    // 构造函数
    User(const string &userID = "", const string &name = "") 
        : userID(userID), name(name) {}

    const string& getID() const {
        return userID;
    }
        // 添加借书记录
    void borrowBook(const BorrowRecord& record) {
        borrowedBooks.Append(record);
    }

    LinkList<BorrowRecord>& getBorrowedBooks() {
        return borrowedBooks;
    }
    // 输出用户借阅记录
    void showBorrowedBooks() const {
        cout << "借阅记录 for " << name << " (ID: " << userID << "):" << endl;
        cout << borrowedBooks;
    }
    const string& getName() const {
        return name;
    }
    void updateUnreturnedBooks() {
        unreturnedbooks.FreeList();  // 先清空链表
        borrowedBooks.findUnreturnedBooks(unreturnedbooks);  // 查找未归还的书
    }
    // 输入流操作符重载
    friend istream &operator>>(istream &in, User &u) {
        // 只输入用户ID和用户名
        in >> u.userID >> u.name;
        return in;
    }
    
    // 输出流操作符重载
    friend ostream &operator<<(ostream &out, const User &u) {
        out << u.userID <<"     " << u.name ;
        return out;
    }

};



class BorrowRecord {        //包含书名、借阅日期、归还日期
    string bookName;
    string borrowDate;
    string returnDate;
    
public:
    // 默认构造函数
    BorrowRecord() : bookName(""), borrowDate(""), returnDate("") {}

    BorrowRecord(const string &bookName, const string &borrowDate, const string &returnDate = "") 
        : bookName(bookName), borrowDate(borrowDate), returnDate(returnDate) {}

    // 重载的输入输出流操作符
    friend ostream & operator<<(ostream &out, const BorrowRecord &record) {
        out << record.bookName 
            << ", 借于: " << record.borrowDate 
            << ", 还于: " << (record.returnDate.empty() ? "尚未归还" : record.returnDate);
        return out;
    }
    const string& getTitle() const {
        return bookName;
    }

    const string getReturndate() const
    {
        return returnDate;
    }

    friend istream & operator>>(istream &in, BorrowRecord &record) { 
        //cout<<"请输入数据域数据(ISBNTab借阅日期换行): "
        in >> record.bookName >> record.borrowDate ;
        return in;
    
    }
    const string getBookName() const
    {
        return bookName;
    }
    
    void setReturnDate(const string &newReturnDate) {
        returnDate = newReturnDate;
    }
};
/* void returnBook(User* userToCheck) {
    LinkList<BorrowRecord>& records = userToCheck->getBorrowedBooks();
    vector<Node<BorrowRecord>*> unreturnedBooks;  // 存储未归还的书籍节点指针

    // 显示未归还书籍并获得数量
    int unreturnedCount = records.displayUnreturnedBooks(unreturnedBooks);
    if (unreturnedCount == -1) {
        return;  // 没有未归还书籍，直接返回
    }

    // 提示用户选择要归还的书籍
    int choice;
    cout << "请输入你想要归还的书籍编号 (1-" << unreturnedCount << "): ";
    cin >> choice;

    // 检查输入是否有效
    if (choice < 1 || choice > unreturnedCount) {
        cout << "无效选择!" << endl;
        return;
    }

    // 获取用户选择的书籍
    Node<BorrowRecord>* selectedBook = unreturnedBooks[choice - 1];
    
    // 输入归还日期
    string returnDate;
    cout << "请输入归还日期 (格式: YYYY-MM-DD): ";
    cin >> returnDate;

    // 更新借阅记录的归还日期
    //selectedBook->getData().setReturnDate(returnDate);  // 使用 setter 函数进行修改
    BorrowRecord modifiedRecord = *selectedBook;  // 拷贝现有记录
    modifiedRecord.setReturnDate(returnDate);     // 修改归还日期

    // 使用 ModifyData 更新当前结点数据
    borrowedBooks.ModifyData(modifiedRecord);

    // 还书成功，提示用户
    cout << "书籍《" << selectedBook-> getData().getBookName()<< "》已归还!" << endl;
}







 */