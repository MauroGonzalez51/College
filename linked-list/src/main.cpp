#include <iostream>
#include <cstdint>
#define u32 uint32_t

template <typename T>
class LinkedList {
	private:

		/**
		 * @brief Basic node for storing data in a linked list
		 * 
		 * This structure represents a single node in a linked list
		 * 
		 * @param T The type of the data to be stored in the node
		 *
		*/

		struct Node {

			/**
			 * @var data
			 * The data value associated with the node
			*/
			T data;

			/**
			 * @var nextElement
			 * A pointer to the next node in the linked list, or
			 * nullptr if the node is the last one
			*/
			Node *nextElement;

			/**
			 * Constructor for the Node structure
			 * 
			 * @param value The value to be stored in the node's
			 * data member
			*/
			Node(const T& value) : data(value), nextElement(nullptr) {}	
		};

		/**
		 * @property head
		 * The 'head' of the list, created to iterate over it
		*/

		Node *head;

		/**
		 * @property currentSize
		 * Tracking the currentSize of the list
		*/
		u32 currentSize;

	public:

		/**
		 * @constructor
		 * Default constructor of the class
		 * Sets it's properties to default values
		*/

		LinkedList() : head(nullptr), currentSize(0) {}

		/**
		 * @destructor
		 * Liberate all the memory used
		*/

		~LinkedList() {
			Node *current = this -> head;
			while (current != nullptr) {
				Node *next = current -> nextElement;
				delete current;
				current = next;
			}
		}	

		/**
		 * @method add
		 * @param value {const T&}
		 * New value to be added to the list
		 *  
		 * Complexity:
		 * 
		 * 		- Cases:
		 * 			- No elements in the list: O(1)
		 * 			- More than 1 element: O(n)
		*/

		void add(const T& value) {
			Node *newNode = new Node(value);

			if (this -> head == nullptr) {
				head = newNode;
				this -> currentSize++;
				return;
			}

			Node *current = this -> head;
			while (current -> nextElement != nullptr)
				current = current -> nextElement;

			current -> nextElement = newNode; 
			this -> currentSize++;
		}

		/**
		 * @method add
		 * @param index {const int&}
		 * Remove a element based on the index
		 * 
		 * Complexity:
		 * 
		 * 		- Cases:
		 * 			- No elements in the list: O(1)
		 * 			- More than 1 element: O(n)
		*/

		void removeElement(const int &index) {
			if (index < 0 || index >= this -> currentSize) {
				throw std::out_of_range("Index out of bounds");
			}

			if (index == 0) {
				Node *temp = this -> head;
				this -> head = this -> head -> nextElement;
				delete temp;

				this -> currentSize--;
				return;
			}

			Node *current = this -> head;
			for (u32 i = 0; i < index; i++) 
				current = current -> nextElement;

			Node *temp = current -> nextElement;

			current -> nextElement =  temp -> nextElement;

			delete temp;

			this -> currentSize--;
		}

		T& searchByValue(const T& valueToSearch) {
			if (this -> head -> data == valueToSearch) {
				return this -> head -> data;
			}

			Node* current = this -> head;
			while (current != nullptr) {
				if (current -> data == valueToSearch) {
					return current -> data; 
				}
				current = current->nextElement;
			}

			throw std::out_of_range("Element not found"); 
		}

};

int main(int argc, char **argv) {
    LinkedList<int> *list = new LinkedList<int>();

	list -> add(1);
	list -> add(2);
	list -> add(3);
	list -> add(4);

	return EXIT_SUCCESS;
}
