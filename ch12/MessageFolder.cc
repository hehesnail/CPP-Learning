#include "MessageFolder.h"

// !Message member function implementation
void Message::addFolders(Folder *f) {
	folders.insert(f);
}

void Message::remFolders(Folder *f) {
	folders.erase(f);
}

void Message::save(Folder &f) {
	folders.insert(&f);
	f.addMsg(this);
}

void Message::remove(Folder &f) {
	folders.erase(&f);
	f.remMsg(this);
}

void Message::add_to_Folders(const Message &m) {
	for (auto f: m.folders)
		f->addMsg(this);
}

Message::Message(const Message &m):
	contents(m.contents), folders(m.folders) {
	add_to_Folders(m);
}

void Message::remove_from_Folders() {
	for (auto f: folders) {
		f->remMsg(this);
	}
}

Message::~Message() {
	remove_from_Folders();
}

Message& Message::operator=(const Message &rhs) {
	remove_from_Folders();
	contents = rhs.contents;
	folders = rhs.folders;
	add_to_Folders(rhs);

	return *this;
}

void swap(Message &lhs, Message &rhs) {
	for (auto f: lhs.folders)
		f->remMsg(&lhs);
	for (auto f: rhs.folders)
		f->remMsg(&rhs);

	swap(lhs.contents, rhs.contents);
	swap(lhs.folders, rhs.folders);
	
	for (auto f: lhs.folders)
		f->addMsg(&lhs);
	for (auto f: rhs.folders)
		f->addMsg(&rhs);
}



// !Folder member function implementation
void Folder::addMsg(Message *m) { msgs.insert(m); }
void Folder::remMsg(Message *m) { msgs.erase(m); }

void Folder::add_to_Msg(const Folder &f) {
	for (auto m: f.msgs)
		m->addFolders(this);
}

void Folder::remove_from_Msg() {
	for (auto m: msgs)
		m->remFolders(this);
}

Folder::Folder(const Folder &f):
	msgs(f.msgs) {
	add_to_Msg(f);
}

Folder::~Folder() {
	remove_from_Msg();
}

Folder& Folder::operator=(const Folder &f) {
	remove_from_Msg();
	msgs = f.msgs;
	add_to_Msg(f);

	return *this;
}

void swap(Folder &lf, Folder &rf) {
	for (auto m: lf.msgs)
		m->remFolders(&lf);
	for (auto m: rf.msgs)
		m->remFolders(&rf);

	swap(lf.msgs, rf.msgs);

	for (auto m: lf.msgs)
		m->addFolders(&lf);
	for (auto m: rf.msgs)
		m->addFolders(&rf);
}

int main() {

	return 0;
}