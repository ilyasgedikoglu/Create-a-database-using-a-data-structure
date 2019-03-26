#ifndef _LIST_
#define _LIST_

#include"FileNode.h"
#include"WordNode.h"

template <class T>
class List
{
private:
	FileNode<T> *head;
	int size;

public:
	List() :size(0), head(NULL) {}

	int getSize()const { return size; }

	bool isEmpty()const { return size == 0; }

	bool isFull()const { return false; }

	void StopWords()
	{
		head = NULL;
		size = 0;
		FileNode<T> *walk = NULL;
		int count = 0;
		ifstream fileread;
		fileread.open("StopWords.txt", ios::in);

		while (!fileread.eof())
		{
			if (count == 0)
			{
				FileNode<T> *newNode = new FileNode<T>();
				getline(fileread, newNode->data);
				head = newNode;
				walk = head;
				size++;
				count++;
			}
			else
			{
				FileNode<T> *newNode = new FileNode<T>();
				getline(fileread, newNode->data);
				walk->next = newNode;
				walk = walk->next;
				size++;
			}
		}
		fileread.close();
	}


	void WriteTextFiles()
	{
		List<string> l;
		l.StopWords();

		head = NULL;
		size = 0;
		FileNode<T> *walk = NULL;
		WordNode<T> *walkWord = NULL;
		int count = 0;

		for (int i = 1; i < 9599; i++)
		{
			stringstream ss;
			ss << i;
			string str = ss.str() + ".txt";

			ifstream fileread;
			fileread.open("C:\\AllDocs\\str", ios::in);

			while (!fileread.eof())
			{
				string s;
				bool flag = false;
				fileread >> s;

				if (count == 0)
				{
					FileNode<T> *StopNode = new FileNode<T>();
					StopNode = l.head;
					while (StopNode != NULL)
					{
						if (StopNode->data == s)
						{
							flag = false;
							cout << "Incorrect Word !!!";
							break;
						}
						else
						{
							StopNode = StopNode->next;
						}
					}
					flag = true;

					if (flag == true)
					{
						FileNode<T> *newNode = new FileNode<T>();
						WordNode<T> *newNodeWord = new WordNode<T>();

						newNode->data = s;
						newNode->nextW = newNodeWord;
						newNodeWord->wordData = str + " file";
						head = newNode;
						count++;
						size++;
					}

				}
				else
				{
					flag = true;
					FileNode<T> *StopNode = new FileNode<T>();
					StopNode = l.head;
					while (StopNode != NULL)
					{
						if (StopNode->data == s)
						{
							flag = false;
							cout << "Incorrect Word !!!";
							break;
						}
						else
						{
							StopNode = StopNode->next;
						}
					}
					flag = true;
					if (flag == true)
					{
						FileNode<T> *newNode = new FileNode<T>();
						WordNode<T> *newNodeWord = new WordNode<T>();

						walk = head;
						if (walk != NULL) {
							while (walk != NULL)
							{
								if (walk->data == s)
								{
									newNodeWord->wordData = str + " file";
									walkWord = walk->nextW;
									while (walkWord != NULL)
									{
										if (walkWord->next == NULL)
										{
											walkWord->next = newNodeWord;
											break;
										}
										else
										{
											walkWord = walkWord->next;
										}
									}
								}
								else if (walk->next == NULL)
								{
									newNode->data = s;
									walk->next = newNode;
									newNode->nextW = newNodeWord;
									newNodeWord->wordData = str + " file";
									size++;
									break;
								}
								else
								{
									walk = walk->next;
								}
							}
						}
					}
				}
			}
			fileread.close();
		}
	}


	void traverse()const
	{
		FileNode<T> *walk = head;
		if (walk != NULL) {
			while (walk != NULL)
			{
				cout << walk->data << "\n";
				walk = walk->next;
			}
			cout << "NULL\n";
		}
		else
			cout << "Empty" << endl;
	}

	string Search(string word)
	{
		FileNode<T> *walk = head;
		WordNode<T> *walkWork = NULL;
		string index = "File names where the word is located\n";

		if (walk != NULL)
		{
			while (walk != NULL)
			{
				if (word == walk->data)
				{
					walkWork = walk->nextW;

					if (walkWork != NULL)
					{
						while (walkWork != NULL)
						{
							index += walkWork->wordData + "\n";
							walkWork = walkWork->next;
						}
						return index;
					}
				}
				walk = walk->next;
			}
			if (walk == NULL)
			{
				return "There is no such word";
			}
		}
	}
};

#endif