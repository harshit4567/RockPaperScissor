A simple stone paper scissor implementation.

**Prequisites**
1. Install bazel : https://bazel.build/install.
2. C++17 or later compiler. 


**How to run the program ?**
1. `bazel build //:main --cxxopt='-std=c++17'`
2. `.GLOG_log_dir=./logs bazel-bin/main` 


R, P, S are the valid input options for Rock, Paper & Scissors respectively
Enter "exit" to exit the games

Logs are available in the logs directorty in the same directory

**How to run the unit test suite ?**
* Run the following command : 
  *  ```bazel test --test_output=all //:rock_paper_scissor_test --cxxopt='-std=c++17'```