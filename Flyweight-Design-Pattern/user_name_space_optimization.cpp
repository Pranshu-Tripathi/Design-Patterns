#include <string>
#include <iostream>
#include <map>



/**
 * There are lots of people with same names.
 * Its memory heavy if we save the names again and again.
 * Rather we store their hashes.
*/
static std::map<int, std::string> key_to_names;
static std::map<std::string, int> names_to_key; // Can use bimap here!

class User
{   
    public:
        User(const std::string& first_name, const std::string& last_name) :
            first_name{add(first_name)}, last_name{add(last_name)}
        {
        }

        std::string getFullName()
        {
            return key_to_names[first_name] + "(" + std::to_string(first_name) + ")" +
             " " + key_to_names[last_name] + "(" + std::to_string(last_name) + ")";
        }
    private:
        int add(const std::string& s)
        {
            auto it = names_to_key.find(s);
            if(it != names_to_key.end())
            {
                return it->second;
            }
            else
            {
                int id = key_to_names.size();
                key_to_names[id] = s;
                names_to_key[s] = id;
                return id;
            }
        }
        int first_name;
        int last_name;
};

int main()
{
    User user1{"John", "Doe"};
    User user2{"Jane", "Doe"};

    std::cout << user1.getFullName() << std::endl;
    std::cout << user2.getFullName() << std::endl;
}
