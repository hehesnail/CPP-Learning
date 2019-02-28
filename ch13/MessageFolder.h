// !ex13.34, 13.16, 13.37
#ifndef __MsgFolder__
#define __MsgFolder__

#include <string>
#include <set>

using namespace std;

class Folder;

class Message {
	friend class Folder;
	friend void swap(Message&, Message&);

public:
	explicit Message(const string &str=" "):
		contents(str) { }
	Message(const Message&);
	Message& operator=(const Message&);
	~Message();
	void save(Folder&);
	void remove(Folder&);
	void addFolders(Folder*);
	void remFolders(Folder*);

private:
	string contents;
	set<Folder*> folders;
	void add_to_Folders(const Message&);
	void remove_from_Folders();
};

void swap(Message&, Message&);


class Folder {
	friend class Message;
	friend void swap(Folder&, Folder&);

public:
	Folder()=default;
	Folder(const Folder&);
	Folder& operator=(const Folder&);
	~Folder();
	void addMsg(Message*);
	void remMsg(Message*);

private:
	set<Message*> msgs;
	void add_to_Msg(const Folder &);
	void remove_from_Msg();
};

void swap(Folder&, Folder&);

#endif