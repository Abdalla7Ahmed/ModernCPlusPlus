#include<iostream>
#include <stack>
#include <string>

struct info
{
    std::string name ;
    std::string phone ;
    std::string email;
    int  age;
    int user_id;
};

class AddressBook {
private:
    std::stack<struct info> lifoStack;
public:
    AddressBook()=default;
    ~AddressBook()=default;
    void list();
    void addContact(info &contact);
    void removeContact(int user_id);
    void remove_all();
    void search(int user_id);
    void printContact(info &contact);
};

    void AddressBook::list()
    {
        std::stack<struct info> temp = lifoStack;
        if(temp.empty())
        {
            std::cout<<"No Contacts to list"<<std::endl;
            return ;
        }
        std::cout <<"====== Listing all users ======= "<<std::endl;
        while (!temp.empty()) {
        std::cout << "Name: " << lifoStack.top().name << std::endl;
        std::cout << "Phone: " << lifoStack.top().phone << std::endl;
        std::cout << "Email: " << lifoStack.top().email << std::endl;
        std::cout << "Age: " << lifoStack.top().age << std::endl;
        std::cout << "User ID: " << lifoStack.top().user_id << std::endl;
        temp.pop();
        std::cout<<"================================================================"<<std::endl;
        }

    }
    void AddressBook::addContact(info &contact)
    {
        info contact_info;
        contact_info.name = contact.name;
        contact_info.phone = contact.phone;
        contact_info.email = contact.email;
        contact_info.age = contact.age;
        contact_info.user_id = contact.user_id;
        lifoStack.push(contact_info);
        std::cout << "Contact added successfully!" << std::endl;
    }
    void AddressBook::removeContact(int user_id)
    {
    std::stack<struct info> temp;

    // Pop elements from lifoStack and push to temp until finding the contact
    while (!lifoStack.empty()) {
        if (lifoStack.top().user_id == user_id) {
            lifoStack.pop(); // Remove the contact from lifoStack
            break;
        }
        temp.push(lifoStack.top());
        lifoStack.pop();
    }

    // Restore the elements back to lifoStack from temp
    while (!temp.empty()) {
        lifoStack.push(temp.top());
        temp.pop();
    }
        

    }
    void AddressBook::remove_all()
    {
        while (!lifoStack.empty())
        {
            lifoStack.pop();
        }
    }

    void AddressBook::search(int user_id)
    {
        std::stack<struct info> temp = lifoStack;

        if(temp.empty())
        {
            std::cout<<"No Contacts to search "<<std::endl;
            return ;
        }
        while (!temp.empty()) 
        {
            if(temp.top().user_id == user_id)
            {
                std::cout << "Name: " << lifoStack.top().name << std::endl;
                std::cout << "Phone: " << lifoStack.top().phone << std::endl;
                std::cout << "Email: " << lifoStack.top().email << std::endl;
                std::cout << "Age: " << lifoStack.top().age << std::endl;
                std::cout << "User ID: " << lifoStack.top().user_id << std::endl;
                return ;
            }
            else
            {
                temp.pop();
            }
        }
        std::cout<<"No Contact found"<<std::endl;
    }
    void AddressBook::printContact(info &contact)
    {
        std::cout << "Name: " << contact.name << std::endl;
        std::cout << "Phone: " << contact.phone << std::endl;
        std::cout << "Email: " << contact.email << std::endl;
        std::cout << "Age: " << contact.age << std::endl;
        std::cout << "User ID: " << contact.user_id << std::endl;

    }

int main(void)
{
    info s1;
    AddressBook ab;

    int choice ,temp; 
    std::cout<<"Welcome to your vafourite address book !!"<<std::endl;
    while(1)
    {
        std::cout<<"|==============================|"<<std::endl;
        std::cout<<"| What do you want to do?      |"<<std::endl;
        std::cout<<"\t |  1.List    | List all users"<<std::endl;
        std::cout<<"\t |  2.Add     | Add a new user"<<std::endl;
        std::cout<<"\t |  3.Delete  | Delete an user"<<std::endl;
        std::cout<<"\t |  4.Delete  | Delete all users"<<std::endl;
        std::cout<<"\t |  5.Search  | Search on user "<<std::endl;
        std::cout<<"\t |  6.Exit    | Exit the application"<<std::endl;
        std::cout<<" ***** Enter your choice: ";
        std::cin>>choice;
        switch(choice)
        {
            case 1:
                ab.list();
                break;
            case 2:
            {
                info contact;
                std::cout<<"Enter name: ";
                std::cin>>contact.name;
                std::cout<<"Enter phone: ";
                std::cin>>contact.phone;
                std::cout<<"Enter email: ";
                std::cin>>contact.email;
                std::cout<<"Enter age: ";
                std::cin>>contact.age;
                std::cout<<"Enter user id: ";
                std::cin>>contact.user_id;
                ab.addContact(contact);
                break;
            }
            case 3:
            {
                int temp;
                std::cout<<"Enter user id to delete: ";
                std::cin>>temp;
                ab.removeContact(temp);
                break;
            }
            case 4:
            {
                ab.remove_all();
                break;
            }
            case 5:
            {
                std::cout<<"Enter user id: to search: ";
                std::cin>>temp;
                ab.search(temp);
                break;
            }
            case 6:
                exit(1);
                break;
        }

    }
   


    return 0;
}
