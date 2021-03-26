#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <iterator>


using namespace std;

// add nodes
// add edges

class Edge;

struct Node{
private:
    string id;
    string label;
public:    
    Node(string i, string l){
        id = i;
        label=l;
    }
    friend Edge;
    friend ostream& operator<<(ostream& os, Node *other)
    {
        return os <<other->id<< " [label="<<other->label<<"]";
    }

    string getID()
    {
        return id;
    }

    string getLabel()
    {
        return label;
    }

    void setID(string _id)
    {
        id = _id;
    }

    void setLabel(string _label)
    {
        label = _label;
    }

};

struct Edge
{
    map<string,string> attributes;
    map<string,string>::iterator it;
    
    Node* start;
    Node* end;

    Edge(Node* s,Node* e)
    {
        start = s;
        end = e;
    }

    friend Node;

    void addAttribute(string key,string value)
    {
            attributes.insert(pair<string, string>(key, value));
    }
    friend ostream& operator<<(ostream& os, Edge& other){
        os << other.start->getID()<<"->"<<other.end->getID();
        os << " [";

        other.it = other.attributes.begin();
        while (other.it != other.attributes.end())
        {
            os << " " << other.it->first << " = " << other.it->second;
            other.it++;
        }

        os << " ]";
        return os;
    }
};

struct Graphviz
{
    void Print(){
        cout<<"digraph G {\nstart -> a0;\nstart -> b0;\na1 -> b3;\n}";
    }
};

int main()
{
    ifstream infile;
    infile.open("input.txt");

    Graphviz G;
    string graph;
    infile >> graph;
    if (graph == "digraph")
    {
        G.Print();
    }

    int size;
    infile >> size;

    Node** nodes = new Node *[size];

    while ()

    Edge E1(N1,N2);
    E1.addAttribute("label", "355");
    cout<<N1<<endl;
    cout<<N2<<endl;
    cout<<E1<<endl;
    

    infile.close();
    return 0;
}