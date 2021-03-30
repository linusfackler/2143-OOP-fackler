///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Linus Fackler
// Email:            linus.fackler@iCloud.com
// Label:            P02
// Title:            Program 02 - Graphviz Class
// Course:           CMPS 2143
// Semester:         Spring 2021
//
// Description:
//      This program prints out a code for Graphviz with an input file.
//      It creates Nodes with an ID and label from the input file data.
//      It then creates Edges from one Node to another with attributes.
//
// Usage:
//       g++ main.cpp -o main
//       main
//
// Files:        
//       main.cpp
//       input.txt
//       output.txt
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <iterator>

using namespace std;


struct Node{
private:
    string id;              // string for node ID
    string label;           // string for node label

    map<string,string> attributes;      // map for attributes
    map<string,string>::iterator it;    // iterator to go through maps

public:    
    Node(string _id, string _label){    // overloaded constructor for Node
        id = _id;
        label = _label;
    }

    string getID()                      // getter for Node ID
    {
        return id;
    }

    string getLabel()                   // getter for Node label
    {
        return label;
    }

    void setID(string _id)              // setter for Node ID
    {
        id = _id;
    }

    void setLabel(string _label)        // setter for Node label
    {
        label = _label;
    }

    /**
    * Description:
    *      this function lets you add attributes for to the Node
    *      like color or shape by inserting into the map attributes
    * Params:
    *      string key and string value
    *      key   ->    color, shape, ...
    *      value ->    red, diamond, ...
    * 
    * Returns:
    *      Void, no return
    */
    void addAttribute(string key,string value)
    {
            attributes.insert(pair<string, string>(key, value));
    }

    //prints out Node
    friend ostream& operator<<(ostream& os, Node *other)
    {
        os << "\t" << other->id<< " [ label = \""<<other->label << "\"";
        // \t so not on same height as {  }
        // prints out:  DE [ label = "Germany" 

        other->it = other->attributes.begin();
        while (other->it != other->attributes.end())
        {        
            os << " " << other->it->first << " = " << other->it->second;
            other->it++;
        }   // iterates through all the maps, so multiple ones can be created

        os << " ]";

        return os;
    }

};

struct Edge
{
    map<string,string> attributes;      // map for attributes
    map<string,string>::iterator it;    // iterator to go through maps
    
    string start, end;             // strings for start and end

    Edge(string s, string e)        // overloaded constructor
    {
        start = s;
        end = e;
    }

    friend Node;

    /**
    * Description:
    *      this function lets you add attributes for to the Node
    *      like label or color by inserting into the map attributes
    * Params:
    *      string key and string value
    *      key   ->    label, color, ...
    *      value ->    69 miles, blue, ...
    * 
    * Returns:
    *      Void, no return
    */
    void addAttribute(string key,string value)
    {
            attributes.insert(pair<string, string>(key, value));
    }

    friend ostream& operator<<(ostream& os, Edge* other){
        os << "\t" << other->start <<"->"<<other->end;
        os << " [";
        // \t so not on same height as {  }
        // prints out: DE->US [ 

        other->it = other->attributes.begin();
        while (other->it != other->attributes.end())
        {
            os << " " << other->it->first << " = \"" << other->it->second 
                << "\"";
            other->it++;
        }   // iterates through all the maps, so multiple ones can be created

        os << " ]";
        return os;
    }
};

struct Graphviz
{

    /**
    * Description:
    *      this function prints out the graph with Nodes and Edges to ostream
    * Params:
    *      nodes array, edges array, size of nodes array, size of edges array
    *      and ostream by reference
    * 
    * Returns:
    *      Void, no return
    */
    void Print(Node **nodes, Edge **edges, int sizeN, int sizeE, ostream &out)
    {
        out << "digraph G\n{\n";

        for (int i = 0; i < sizeN; i++)
        {
            out << nodes[i] << endl;
        }   // prints out all nodes

        out << "\n\n";

        for (int i = 0; i < sizeE; i++)
        {
            out << edges[i] << endl;
        }   // prints out all edges

        out << "}";

    }
};

int main()
{
    ifstream infile;            // file stream input
    ofstream outfile;           // file stream output
    infile.open("input.txt");   // opens input file
    outfile.open("output.txt"); // opens output file

    Graphviz G;                 // Graphviz instance created
    string graph;
    int sizeN, sizeE, dist;
    string label, id;
    string start, end;


    infile >> graph;            // reads in "graphviz" in this case
    infile >> sizeN;            // reads in number of nodes

    Node **nodes = new Node *[sizeN];   // array of Nodes of sizeN created

    for (int i = 0; i < sizeN; i++)
    {
        infile >> id >> label;          // reads in ID and Label for Node

        nodes[i] = new Node(id, label); // created Node i with ID & Label
    }


    infile >> sizeE;                    // reads in number of edges
    Edge **edges = new Edge *[sizeE];   // array of Edges of sizeE created

    for (int i = 0; i< sizeE; i++)
    {
        infile >> start >> end >> dist; // reads in start & end ID & distance

        edges[i] = new Edge(start, end);// new edge i with start & end string
        edges[i]->addAttribute("label", to_string(dist)+ " miles");
            // adds attribute label with value distance to edge i
    }

    if (graph == "digraph")
    {
        G.Print(nodes, edges, sizeN, sizeE, outfile);
            // print function for Graph if it's a digraph
    }

    else
    {
        cout << "Unknown graph diagram!\n";
        exit(0); // if no digraph then program exits with error message
    }

    infile.close();     // infile closed
    outfile.close();    // outfile closed
    return 0;
}