#include <vector>
#include <iostream>
#include <unordered_map>
#include <sstream>
#include <string>

using namespace std;

vector<vector<int>> emailThread(vector<string> &str) {
    unordered_map<string, int> mp;
    int tids = 0;
    vector<vector<int>> output;
    for (auto s : str) {
        stringstream ss(s);
        string temp;
        while (getline(ss, temp, ',')) {

        }
    }
}

/*
    res = []
    dialogue_dict = {}
    thread_id = 0 # self-incrementing
    for email in emails:
        sender, receiver, content = email.split(", ")
        content_l = content.split("---")

        if sender > receiver:
            sender, receiver = receiver, sender
        dialogue = (sender, receiver)

        if dialogue not in dialogue_dict:
            thread_id += 1
            dialogue_dict[dialogue] = {
                thread_id: content_l
            } # key is thread_id, value is (mail_content, session_id)
            res.append([thread_id, len(content_l)])
        else: # for existing dialog
            thread_dict = dialogue_dict[dialogue]
            old_contents = content_l[1:]

            found_old = False

            for (tid, thread_content) in thread_dict.items():
                if thread_content == old_contents:
                    found_old = True
                    thread_dict[tid] = content_l
                    res.append([tid, len(content_l)])
                    break

            if not found_old:
                thread_id += 1 # create a new thread
                thread_dict[thread_id] = content_l
                res.append([thread_id, len(content_l)])
    return res

*/