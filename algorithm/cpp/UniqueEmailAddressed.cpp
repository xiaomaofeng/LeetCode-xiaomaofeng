/*
929    :Unique Email Addresses
Source :https://leetcode-cn.com/problems/unique-email-addresses/
Author :xiaomaofeng
Date   :2018-12-13

Problem Description:
Every email consists of a local name and a domain name, separated by the @ sign.

For example, in alice@leetcode.com, alice is the local name, and leetcode.com is the domain name.

Besides lowercase letters, these emails may contain '.'s or '+'s.

If you add periods ('.') between some characters in the local name part of an email address, 
mail sent there will be forwarded to the same address without dots in the local name.  
For example, "alice.z@leetcode.com" and "alicez@leetcode.com" forward to the same email address.  (Note that this rule does not apply for domain names.)

If you add a plus ('+') in the local name, everything after the first plus sign will be ignored. This allows certain emails to be filtered, 
for example m.y+name@email.com will be forwarded to my@email.com.  (Again, this rule does not apply for domain names.)

It is possible to use both of these rules at the same time.

Given a list of emails, we send one email to each address in the list.  How many different addresses actually receive mails?

Example 1:

Input: ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
Output: 2
Explanation: "testemail@leetcode.com" and "testemail@lee.tcode.com" actually receive mails
*/


class Solution {
public:

	string GetNoPointString(string Str)
	{
		size_t atPos;
		size_t pos;
		atPos = Str.find('@');
		//string tempStr;
		// tempStr=Str;
		pos = Str.rfind('.', atPos);
		if (pos == string::npos)
			return Str;
		Str = Str.substr(0, pos) + Str.substr(pos + 1, string::npos);
		return GetNoPointString(Str);


	}


	int numUniqueEmails(vector<string>& emails) {
		size_t atPos;
		size_t plusPos;
		vector<string>emailStress;
		string tempStr;
		bool bfirstPush = true;

		for (int i = 0; i<emails.size(); i++)
		{
			bool bpushFlag = true;
			atPos = emails[i].find('@');
			plusPos = emails[i].find('+');
			if (plusPos != string::npos)
			{
				emails[i] = emails[i].substr(0, plusPos) + emails[i].substr(atPos, string::npos);
			}
			emails[i] = GetNoPointString(emails[i]);
			if (bfirstPush)
			{
				emailStress.push_back(emails[i]);
				bfirstPush = false;
			}
			else
			{
				for (int j = 0; j<emailStress.size(); j++)
				{
					if (emails[i] == emailStress[j])
					{
						bpushFlag = false;
						break;
					}

				}
				if (bpushFlag)
				{
					emailStress.push_back(emails[i]);
				}

			}

		}
		return emailStress.size();

	}
};