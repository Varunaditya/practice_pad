""""
Given a list accounts, each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name,
and the rest of the elements are emails representing emails of the account.
Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some email
that is common to both accounts. Note that even if two accounts have the same name, they may belong to different people
as people could have the same name. A person can have any number of accounts initially, but all of their accounts
definitely have the same name.
After merging the accounts, return the accounts in the following format: the first element of each account is the name,
and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.
"""


def merge_accounts(accounts: list) -> list:
    merged_accounts, temp = list(), set()
    visited = list()
    while accounts:
        temp = set()
        current_account = accounts.pop(0)
        if len(accounts) < 1:
            merged_accounts.append(sorted(current_account))
            break
        for i in range(1, len(accounts)):
            [temp.add(i) for i in current_account]
            if current_account[0] == accounts[i][0]:
                if len(set(current_account[1:]).intersection(set(accounts[i][1:]))):
                    [temp.add(i) for i in accounts[i][1:]]
                    visited.append(accounts[i])
        visited.append(current_account)
        if list(temp) not in merged_accounts and len(temp) > 0:
            merged_accounts.append(sorted(list(temp)))
    return merged_accounts


def main():
    accounts = [["John", "johnsmith@mail.com", "john00@mail.com"],
                ["John", "johnnybravo@mail.com"],
                ["John", "johnsmith@mail.com", "john_newyork@mail.com"],
                ["Mary", "mary@mail.com"]]
    ans = merge_accounts(accounts)
    print(ans)


if __name__ == "__main__":
    main()
