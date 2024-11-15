#include <iostream>
#include "LibraryManagement.h"
//#include"newLibraryManagement.h"
#include "LinkList.h"
using namespace std;


int main() {
    int choice;
    LinkList<Book> libraryBooks;
    LinkList<User> libraryUsers;
    char Booklist[80] = "Booklist.txt";
    char AccountData[80] = "AccountData.txt";
	Node<User> *pU;
    Node<Book> *pB;
	int a,b;
	a = libraryBooks.Load(Booklist);
    b = libraryUsers.Load(AccountData);
    cout << "\n已从 " << Booklist << " 文件中读取了 " << a << " 个结点的数据" << endl;
    cout << "\n已从 " << AccountData << " 文件中读取了 " << b << " 个结点的数据" << endl;
    BorrowRecord record;
    Book x;
    User y;
    string str;
    string userID, userName;
    do {
            cout << "**************************************" << endl;
            cout << "*                                    *" << endl;
            cout << "*    欢迎进入图书馆管理系统          *" << endl;
            cout << "*                                    *" << endl;
            cout << "**************************************" << endl;
            cout << "*                                    *" << endl;
            cout << "*           请选择:                  *" << endl;
            cout << "*                                    *" << endl;
            cout << "*     1. 进入管理员系统              *" << endl;
            cout << "*     2. 进入借阅系统                *" << endl;
            cout << "*     0. 退出系统                    *" << endl;
            cout << "*                                    *" << endl;
            cout << "**************************************" << endl;
            cout << "请输入选项: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // 管理员系统逻辑
                int choice1;
                do {
                    cout << "\n*******************************************" << endl;
                    cout << "*                                         *" << endl;
                    cout << "*            管理员系统                   *" << endl;
                    cout << "*                                         *" << endl;
                    cout << "*******************************************" << endl;
                    cout << "*                                         *" << endl;
                    cout << "*     1. 增加书籍                        *" << endl;
                    cout << "*     2. 删除书籍                        *" << endl;
                    cout << "*     3. 查找书籍                        *" << endl;
                    cout << "*     4. 显示所有书籍                    *" << endl;
                    cout << "*     5. 增加读者                        *" << endl;
                    cout << "*     6. 删除读者                        *" << endl;
                    cout << "*     7. 显示所有读者                    *" << endl;
                    cout << "*     8. 查找用户并输出借阅记录          *" << endl;
                    cout << "*     9. 数据写入文件                    *" << endl;
                    cout << "*    10. 返回上一界面                    *" << endl;
                    cout << "*                                         *" << endl;
                    cout << "*******************************************" << endl;


                    cout << "请输入你的选择: ";
                    cin >> choice1;

                    switch (choice1) {
                        case 1: {
                            cout << "增加书籍功能..." << endl;
                            cout << "请选择:1.增加新书 2.增加已有书籍副本数量" << endl;
                            int choice2;
                            cin >> choice2;
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            if (choice2 == 1) {
                                cout << "请输入数据域数据(编号Tab标题Tab作者Tab年份Tab副本数量换行): ";
                                cin >> x;
                                libraryBooks.Append(x);
                                libraryBooks.Save(Booklist);
                                cout << "已添加新书" << endl;
                            } else {
                                //cout << "请输入数据域数据(编号Tab标题Tab作者Tab年份Tab副本数量换行): ";
                                std::string bookTitle;
                                cout << "请输入书名进行查找: ";
                                getline(cin, bookTitle);  // 让用户输入书名

                                Book* nodeToAddbook = libraryBooks.findByTitle(bookTitle);
                                if (nodeToAddbook != nullptr) {
                                    nodeToAddbook->addBook();
                                    cout << "已增加副本" << endl;
                                } else {
                                    cout << "没有找到相应书籍" << endl;
                                }
                                libraryBooks.Save(Booklist);
                            }
                            break;
                        }
                        case 2: {
                            cout << "删除书籍功能..." << endl;
                            cout << "请输入书名：";
                            getline(cin >> ws, str);
      
                            Book* nodeToDelete = libraryBooks.findByTitle(str);
                            if (nodeToDelete != nullptr) {
                                libraryBooks.DeleteCurNode();
                                cout << "已删除" << endl;
                                libraryBooks.Save(Booklist);
                            } else {
                                cout << "没有找到相应书籍" << endl;
                            }
                            break;
                        }
                        case 3: {
                            cout << "查找书籍功能..." << endl;
                            cout << "输入书名：";
                            getline(cin >> ws, str);
                           
                            Book* nodeToFind = libraryBooks.findByTitle(str);
                            if (nodeToFind != nullptr) {
                                cout <<endl<< *libraryBooks.findByTitle(str)<<endl;
                            } else {
                                cout << "没有找到相应书籍" << endl;
                            }
                            break;
                        }
                         case 4:{
                            cout << libraryBooks;
                            
                            break;
                        }
                        case 5: {
                            cout << "增加读者功能..." << endl;
                            cout << "请输入数据域数据(用户IDTab用户名换行): ";
                            cin >> y;
                            libraryUsers.Append(y);
                            libraryUsers.Save(AccountData);
                            cout << "已添加用户" << endl;
                            break;
                        }
                        case 6: {
                            cout << "删除读者功能..." << endl;
                            cout << "请输入用户ID: ";
                            getline(cin >> ws, userID);
                            cout << "请输入用户名: ";
                            getline(cin >> ws, userName);
                            User* userToDelete = libraryUsers.findUser(userID, userName);
                            if (userToDelete != nullptr) {
                                libraryUsers.DeleteCurNode();
                                cout << "已删除" << endl;
                                libraryUsers.Save(AccountData);
                            } else {
                                cout << "没有找到相应用户" << endl;
                            }
                            break;
                        }
                        case 7: {
                            cout << "显示所有读者功能..." << endl;
                            //libraryUsers.ShowList();
                            cout << libraryUsers;
                            break;
                        }
                        case 8: {
                            cout << "查找用户并输出借阅记录功能..." << endl;
                            cout << "请输入用户ID: ";
                            getline(cin >> ws, userID);
                            cout << "请输入用户名: ";
                            getline(cin >> ws, userName);
                            User* userToFind = libraryUsers.findUser(userID, userName);
                            cout << userToFind->getBorrowedBooks();

                            break;
                        }
                        case 9: {
                            cout << "数据写入文件功能..." << endl;
                            libraryUsers.Save(AccountData);
                            libraryBooks.Save(Booklist);
                            cout <<"已成功保存"<<endl;
                            break;
                        }
                        case 10:
                            cout << "返回上一界面..." << endl;
                            break;
                    
                        default:
                            cout << "无效选择，请重新选择。" << endl;
                            break;

                    }
                } while (choice1 != 10);
                break;
            }
            case 2: {
                // 读者系统逻辑
                string readerID;
                string readerName;
                int choice2;
                    cout << "\n*******************************************" << endl;
                    cout << "*                                         *" << endl;
                    cout << "*               读者系统                  *" << endl;
                    cout << "*                                         *" << endl;
                    cout << "*******************************************" << endl;
                    cout << "\n请输入读者ID: ";
                    cin >> readerID;
                    cout << "\n请输入姓名: ";
                    cin >> readerName;
                    // 检查用户ID是否在用户列表中
                    User* userToCheck = libraryUsers.findUser(readerID, readerName); // 假设您可以只通过ID查找用户
                    if (userToCheck != nullptr) {
                        cout << "欢迎, 读者 " << readerID <<readerName<< "!" << endl;
                        userToCheck = libraryUsers.findUser(readerID, readerName); 
                        
                    } else {
                        cout << "未找到该读者，请重新输入。" << endl; // 提示用户重新输入
                        break; 
                    }
                
                
                do {
                    cout << "*******************************************" << endl;
                    cout << "*                                         *" << endl;
                    cout << "*     1. 借书                             *" << endl;
                    cout << "*     2. 还书                             *" << endl;
                    cout << "*     3. 查看借阅记录                     *" << endl;
                    cout << "*     4. 返回上一界面                     *" << endl;
                    cout << "*                                         *" << endl;
                    cout << "*******************************************" << endl;
                    cout << "请输入你的选择: ";
                    cin >> choice2;

                    switch (choice2) {
                        case 1: { // 借书功能
                            cout << "请输入书名进行查找: ";
                            string bookTitle;
                            cin.ignore();
                            getline(cin, bookTitle);  // 让用户输入书名

                            Book* bookToBorrow = libraryBooks.findByTitle(bookTitle);
                            if (bookToBorrow != nullptr) {
                                if (bookToBorrow->getCopies() == 0) {
                                    // 如果副本数量为 0，则提示用户该书已全部借出
                                    cout << "抱歉，该书《" << bookToBorrow->getTitle() << "》已全部借出!" << endl;
                                } else {
                                    // 假设读者ID已存储在 readerID 变量中
                                    string borrowDate;
                                    cout << "请输入借阅日期 (格式: YYYY-MM-DD): ";
                                    cin >> borrowDate;

                                    // 创建借阅记录并添加到用户的借阅记录链表中
                                    BorrowRecord newRecord(bookToBorrow->getTitle(), borrowDate);
                                    userToCheck->unreturnedbooks.Append(bookTitle);
                                    userToCheck->borrowBook(newRecord); // userToCheck 是找到的用户对象
                                    cout << userToCheck->getBorrowedBooks();
                                    // 更新书籍副本数量
                                    bookToBorrow->borrowBook();  
                                    libraryBooks.Save(Booklist);  // 保存修改
                                    cout << "借书成功! 剩余副本数量: " << bookToBorrow->getCopies() << endl;
                                }
                            } else {
                                cout << "没有找到该书籍!" << endl;
                            }
                            break;
                        }


                        case 2:{
                            cout << "还书功能..." << endl;
                            bool hasUnreturnedBooks = false;
                            LinkList<BorrowRecord>& records = userToCheck->getBorrowedBooks();
                            userToCheck->updateUnreturnedBooks();  // 更新未归还的书籍链表

                            // 输出未归还的书籍
                            if (!userToCheck->unreturnedbooks.isEmpty()) {
                                hasUnreturnedBooks = true;
                                cout << "以下是你尚未归还的书籍：" << endl;
                                cout<<userToCheck->unreturnedbooks;  
                            } else {
                                cout << "你没有未归还的书籍。" << endl;
                            }

                            if (hasUnreturnedBooks) {
                                string returnbook;
                                cout << "请输入要归还的书籍名称: ";
                                cin.ignore();  // 防止读取到残留的换行符
                                getline(cin, returnbook);

                                // 遍历未归还的书籍链表，检查用户输入的书籍是否在其中
                                if (userToCheck->unreturnedbooks.contains(returnbook)) {  // 假设有 contains() 函数
                                    BorrowRecord* selectedBook = records.findByTitle(returnbook);  // 找到对应的借阅记录
                                    if (selectedBook != nullptr) {
                                        string returnDate;
                                        cout << "请输入归还日期 (格式: YYYY-MM-DD): ";
                                        cin >> returnDate;

                                        // 更新借阅记录的归还日期
                                        selectedBook->setReturnDate(returnDate);
                                        cout << "成功归还书籍: " << returnbook << endl;
                                        Book* nodeToRetrun = libraryBooks.findByTitle(returnbook);
                                        nodeToRetrun->addBook();
                                    } else {
                                        cout << "未找到该书籍的借阅记录!" << endl;
                                    }
                                } else {
                                    cout << "该书不在未归还书籍列表中，请重新输入。" << endl;
                                }
                            }

                            break;
                        }
                        case 3:
                            cout << "查看借阅记录功能..." << endl;
                            cout << userToCheck->getBorrowedBooks();
                            break;
                        case 4:
                            cout << "返回上一界面..." << endl;
                            break;
                        default:
                            cout << "无效选择，请重新选择。" << endl;
                            break;
                    }
                } while (choice2 != 4);
                break;
            }
            case 0:
                cout << "退出系统..." << endl;
                break;
            default:
                cout << "无效选择，请重新选择。" << endl;
                break;
        }
    } while (choice != 0);

    return 0;
}
