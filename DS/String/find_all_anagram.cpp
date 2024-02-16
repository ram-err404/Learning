#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <fstream>
#include <algorithm>

/* Read inputs from file. */
typedef struct read_in_results {
  std::vector<std::string>  dictionary;
  std::vector<std::string>  queries;
} read_in_results_t;

read_in_results_t   read_inputs_from_file(std::string file_name) {
  std::ifstream       fin;
  std::string         temp;
  
  if(file_name.size())
    fin.open(file_name, std::ios::in);
  else {
    std::cerr << "File name missing" << std::endl;
    exit(-1);
  }

  int dict_size;
  fin >> dict_size;
  std::vector<std::string>  dictionary(dict_size);
  for(int i=0; i<dict_size; ) {
    getline(fin, temp);   // equivalent of fin >> temp;
    if("" != temp)
      dictionary[i++] = temp;
  }
  
  int queries_size;
  fin >> queries_size;
  std::vector<std::string>  queries(queries_size);
  for(int i=0; i<queries_size; ) {
    getline(fin, temp);
    if("" != temp)
      queries[i++] = temp;
  }
  fin.close();
  
  /* Fill ret_val and return. */
  read_in_results_t   ret_val;
  ret_val.dictionary    = dictionary;
  ret_val.queries       = queries;

  return ret_val;
}

std::vector<int>  findAllAnagrams(std::vector<std::string>  dictionary,
                                  std::vector<std::string>  queries) {
  for(size_t i=0; i<dictionary.size(); i++)
    sort(dictionary[i].begin(), dictionary[i].end());
  for(size_t i=0; i<queries.size(); i++)
    sort(queries[i].begin(), queries[i].end());
  
  /*Method 1: More optimised. (Passed all Hackerrank test cases)*/ 
  std::unordered_map<std::string, int>   count;
  for(size_t i=0; i<dictionary.size(); i++)
    count[dictionary[i]]++;

  std::vector<int>   res(queries.size(), 0);
  for(size_t i=0; i<queries.size(); i++)
    res[i] = count[queries[i]];

#if 0
  /* Method 2: less optimised. (Passed only 6 test cases)*/
  std::vector<int>   res(queries.size(), 0);
  for(size_t i=0; i<queries.size(); i++) {
    int count=0;
    for(size_t j=0; j<dictionary.size(); j++) {
      if(0 == queries[i].compare(dictionary[j]))
        count++;
    }
    std::cout << count << std::endl;
    res[i] = count;
  }
#endif
  return res;
}

int main() {
  read_in_results_t   in = read_inputs_from_file("find_anagrams_inputs.txt");
  
  std::cout <<"Dictionary: " << std::endl;
  for(auto itr:in.dictionary)
    std::cout << itr <<", ";
  std::cout <<"\nQueries: " << std::endl;
  for(auto itr:in.queries)
    std::cout << itr <<", ";
 
  std::vector<int>    res = findAllAnagrams(in.dictionary, in.queries);

  std::cout <<"\n\nOutput: \n";
  for(size_t i=0; i<res.size(); i++)
    std::cout << in.queries[i] <<": " << res[i] << std::endl;
  
  return 0;
}
