#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>

using namespace std;
struct Order {
  int order_id;
  int deal_id;
  string email;
  string address;
  long long card;
  bool flag;
  Order(char buffer[]) {
    order_id = 0;
    int i = 0;
    for (; buffer[i] != ','; i ++)
      order_id = order_id * 10 + buffer[i] - '0';

    deal_id = 0;
    for ( i ++ ; buffer[i] != ','; i ++)
      deal_id = deal_id * 10 + buffer[i] - '0';

    email = "";
    bool hasAt = false;
    for (i ++ ; buffer[i] != ','; i ++) {
      if (buffer[i] == '.') {
        if (hasAt) email += '.';
      } else if (buffer[i] == '+') {
        for (; buffer[i] != '@'; i ++);
        i --;
      } else if (buffer[i] == '@') {
        hasAt = true;
        email += '@';
      } else {

        if (buffer[i] >= 'A' && buffer[i] <= 'Z') email += buffer[i] - 'A' + 'a';
        else email += buffer[i];
      }
    }

    address = "";
    string word = "";
    for ( i ++; buffer[i] != ','; i ++) {
      if (buffer[i] != ' ') {
        word += buffer[i];
      } else {
        if (word == "road") word = "rd.";
        else if (word == "street") word = "st.";
        address += word;
        address += " ";
        word = "";
      }
    }
    if (word == "road") word = "rd.";
    else if (word == "street") word = "st.";
    if (word != "") {
      address += word;
      address += " ";
    }
    address[address.size() - 1] = ',';
    word = "";
    //city
    for ( i ++; buffer[i] != ','; i ++) address += buffer[i];
    address += ',';

    //state
    for (i ++; buffer[i] != ','; i ++) word += buffer[i];
    if (word == "illinois") word = "il";
    else if (word == "new york") word = "ny";
    else if (word == "california") word = "ca";
    address += word;
    address += ",";

    //zip
    for (i ++; buffer[i] != ','; i ++) address += buffer[i];

    card = 0LL;
    for (i ++; buffer[i]; i ++) card = card * 10 + buffer[i] - '0';
    flag = false;
  }
};

vector<Order *> orders;
bool cmpByEmail(Order *a, Order *b) {
  if (a->deal_id == b->deal_id) {
    if (a->email == b->email) return a->card < b->card;
    return a->email < b-> email;
  }
  return a->deal_id < b->deal_id;
}

bool cmpByAddress(Order *a, Order *b) {
  if (a->deal_id == b->deal_id) {
    if (a->address == b->address) return a->card < b->card;
    return a->address < b->address;
  }
  return a->deal_id < b->deal_id;
}
char buffer[100000];
int main() {
  int t;
  scanf("%d\n", &t);
  orders.clear();
  set<pair<int, string> > st;
  orders.clear();
  while (t --) {
    gets(buffer);
    for (int i = 0; buffer[i]; i ++) {
      if (buffer[i] >= 'A' && buffer[i] <= 'Z') buffer[i] = buffer[i] - 'A' + 'a';
    }
    Order *order = new Order(buffer);
    orders.push_back(order);
  }

  sort(orders.begin(), orders.end(), cmpByEmail);
  for (size_t i = 1; i < orders.size(); i ++) {
    if (orders[i]->deal_id == orders[i - 1] -> deal_id &&
        orders[i] -> email == orders[i - 1] -> email &&
        orders[i] -> card != orders[i - 1]->card) {
      st.insert(make_pair(
                  orders[i]->deal_id,
                  orders[i] -> email
                ));
    }
  }
  for (size_t i = 0; i < orders.size(); i ++) {
    if (st.find(make_pair(orders[i] ->deal_id, orders[i] -> email)) != st.end()) {
      orders[i]->flag = true;
    }
  }

  sort(orders.begin(), orders.end(), cmpByAddress);
  st.clear();
  for (size_t i = 1; i < orders.size(); i ++) {
    if (orders[i - 1 ] -> deal_id == orders[i]->deal_id &&
        orders[i - 1] -> address == orders[i] -> address &&
        orders[i - 1]->card != orders[i]->card) {
      st.insert(make_pair(orders[i]->deal_id,
                          orders[i]->address));
    }
  }

  for (size_t i = 0; i < orders.size(); i ++) {
    if (st.find(make_pair(
                  orders[i]->deal_id,
                  orders[i] -> address)
               ) != st.end()
       ) orders[i] -> flag = true;
  }

  vector<int> ans;
  ans.clear();
  for (size_t i = 0; i < orders.size(); i ++) {
    if (orders[i] -> flag) ans.push_back(orders[i]->order_id);
    delete orders[i];
  }
  sort(ans.begin(), ans.end());
  for (size_t i = 0; i < ans.size(); i ++) {
    if (i) printf(",");
    printf("%d", ans[i]);
  }
  printf("\n");
  return 0;
}
