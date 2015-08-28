#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <math.h>

using namespace std;

class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		if (words.size() == 0) return words;
		int start = 0, end = 0;
		vector<string> output;
		while (start<words.size()){
			end = start;
			int total_sum = words[end].size();
			while (end<(words.size() - 1) && (total_sum + 1 + words[end + 1].size()) <= maxWidth){ end++; total_sum = total_sum + 1 + words[end].size(); }
			generate_string(output, words, start, end, maxWidth);
			start = end + 1;
		}
		return output;
	}

	void generate_string(vector<string>& output, vector<string>& words, int start, int end, int max_Width){
		string temp_out;
		if (end >= words.size() - 1){
			for (int i = start; i < words.size(); i++){ temp_out += (words[i] + " "); }
			if (max_Width>temp_out.size()){ string tail(max_Width - temp_out.size(), ' '); temp_out += tail; output.push_back(temp_out); }
			else{ string final = temp_out.substr(0, max_Width); output.push_back(final); }
		}
		else{
			int letter_sum = 0, word_count = 0;
			for (int i = start; i <= end; i++){ letter_sum += words[i].size(); word_count++; }
			if (word_count == 1){
				string tail(max_Width - letter_sum, ' ');
				temp_out = words[start] + tail;
				output.push_back(temp_out);
			}
			else{
				int space_sum = max_Width - letter_sum;
				int each_slot = space_sum / (word_count - 1);
				int extra = space_sum % (word_count - 1);
				for (int i = start; i<end; i++){
					temp_out += words[i];
					if (extra != 0){ temp_out += string(each_slot + 1, ' '); extra--; }
					else{ temp_out += string(each_slot, ' '); }
				}
				output.push_back(temp_out + words[end]);
			}
		}
	}
};