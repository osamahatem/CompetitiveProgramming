/*
 * 2237 - A Major Problem.cpp
 *
 *  Created on: Dec 9, 2017
 *      Author: Osama Hatem
 */
 
/*
First, we generate all possible major scales following the constraints
specified. We will find that every note can be the key to at most one major
scale. This makes it easy to find the given notes in their respective scale, and
apply the required operation.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

vector<vector<string>> notes = { { "C", "B#" }, { "C#", "Db" }, { "D" }, { "D#",
		"Eb" }, { "E", "Fb" }, { "F", "E#" }, { "F#", "Gb" }, { "G" }, { "G#",
		"Ab" }, { "A" }, { "A#", "Bb" }, { "B", "Cb" } };
map<string, string> other;
int tones[] = { 2, 2, 1, 2, 2, 2, 1 };
map<string, vector<string>> scales;
vector<string> temp;

bool check(string note, bool sharp, bool flat, int mask) {
	int c = note[0] - 'A';
	if (mask & (1 << c))
		return false;
	if (note.size() == 1)
		return true;
	if ((sharp && note[1] == 'b') || (flat && note[1] == '#'))
		return false;
	return true;
}

void getScale(string st, bool sharp, bool flat, int idx, int order, int mask) {
	if (order == 7) {
		temp.push_back(st);
		scales[st] = temp;
		temp.pop_back();
		return;
	}
	for (int i = 0; i < (int) notes[idx].size(); i++) {
		if (check(notes[idx][i], sharp, flat, mask)) {
			temp.push_back(notes[idx][i]);
			bool newSharp = notes[idx][i].size() == 2
					&& notes[idx][i][1] == '#';
			bool newFlat = notes[idx][i].size() == 2 && notes[idx][i][1] == 'b';
			int c = notes[idx][i][0] - 'A';
			int newMask = mask | (1 << c);
			getScale(mask ? st : notes[idx][i], sharp || newSharp,
					flat || newFlat, (idx + tones[order]) % 12, order + 1,
					newMask);
			temp.pop_back();
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	for (int i = 0; i < (int) notes.size(); i++)
		getScale("", 0, 0, i, 0, 0);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	string src, tar, temp;
	vector<string> ins;
	bool flag = 0;
	while (cin >> src, src[0] != '*') {
		if (flag)
			cout << endl;
		flag = 1;
		cin >> tar;
		ins.clear();
		while (cin >> temp, temp[0] != '*')
			ins.push_back(temp);
		if (scales[src].empty()) {
			cout << "Key of " << src << " is not a valid major key" << endl;
		} else if (scales[tar].empty()) {
			cout << "Key of " << tar << " is not a valid major key" << endl;
		} else {
			cout << "Transposing from " << src << " to " << tar << ":" << endl;
			for (int i = 0; i < (int) ins.size(); i++) {
				int idx = find(scales[src].begin(), scales[src].end(), ins[i])
						- scales[src].begin();
				if (idx == (int) scales[src].size())
					cout << "  " << ins[i] << " is not a valid note in the "
							<< src << " major scale" << endl;
				else
					cout << "  " << ins[i] << " transposes to "
							<< scales[tar][idx] << endl;
			}
		}
	}
	return 0;
}
