class Solution {
public:
    // custom split template
    vector<string> split(string str, char delim) {
        string line;
        vector<string> res;
        stringstream ss(str);
        while (getline(ss, line, delim)) res.push_back(line);
        return res;
    }
    
    // steps
    // 1. for each path, split by the ' ', then get the directory path, file name and file content
    // 2. combine the directory path and file name
    // 3. group directoryPath/fileName by file content using hash map
    // 4. build the final ans 
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> m;
        for (auto p : paths) {
            vector<string> path = split(p, ' ');
            string directoryPath;
            for (int i = 0; i < path.size(); i++) {
                if (i == 0) {
                    directoryPath = path[i];
                } else {
                    // e.g. 1.txt
                    string fileName = path[i].substr(0, path[i].find('('));
                    // e.g. abcd
                    string fileContent =  path[i].substr(path[i].find('(') + 1, path[i].find(')') - path[i].find('(') - 1);
                    // e.g. efgh: ["root/a/2.txt","root/c/d/4.txt","root/4.txt"]
                    m[fileContent].push_back(directoryPath + "/" + fileName);
                }
            }
        }
        // build the final answer
        for (auto x : m) {
            // check if there is duplicate
            // e.g. ["root/a 1.txt(abcd) 2.txt(efsfgh)","root/c 3.txt(abdfcd)","root/c/d 4.txt(efggdfh)"]
            if (x.second.size() > 1) {
                // x.second is already the full list of paths
                ans.push_back(x.second);    
            }
        }
        return ans;
    }
};