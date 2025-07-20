
#include "./src/Book.cpp"
#include "./src/Library.cpp"

using namespace std;
void menu(){
    cout<<" 1.Add book :"<<endl;
    cout<<" 2.Display AllBook"<<endl;
    cout<<" 3.Search Book :"<<endl;
    cout<<" 4.Borrow Book :"<<endl;
    cout<<" 5.Return Book :"<<endl;
}
int main(){
    
    int op;
    cout << "Enter a op: ";
    while(!(cin >> op)) {
        cout << "Invalid input! Enter again: ";
        cin.clear();
        cin.ignore(20, '\n');
    }

    cout << "Result: " << op;
    Library l;
   
    do{
        menu();
        cout<<"Enter an option :";
        cin>>op;
        
        if(op==0){
            cout<<"Exitiing.."<<endl;
            return 0;
        }
        switch (op){
            case 1:{
                string title;
                string author;
                string isbn;
                bool isAvailable;
                cout<<"Enter Title book:";
                cin>>title;
                cout<<"Enter Author book:";
                cin>>author;
                cout<<"Enter Isbn book :";
                cin>>isbn;

                Book book(title,author,isbn,isAvailable);
                l.addBook();
                break;
            }
            case 2:{
                l.displayAllBooks();
                break;
            }
            case 3:{
                l.searchBookByTitle();
                break;
            }
            case 4:{
                l.borrowBook();
                break;
            }
            case 5:{
                l.returnBook();
            }

            case 0:
            cout<<"Exiting...."<<endl;
            break;
        
        default:{
            cout<<"Borrow ot ban...."<<endl;
        }
            break;
        }
    }while (op!=0)
    return 0;
}