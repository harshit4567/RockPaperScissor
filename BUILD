cc_library(
  name = "rock_paper_scissor",
  srcs = ["rock_paper_scissor.cc","rock_paper_scissor.h"],
  deps = ["@com_github_google_glog//:glog"]
)

cc_test(
  name = "rock_paper_scissor_test",
  size = "small",
  srcs = ["rock_paper_scissor_test.cc"],
  deps = ["@com_google_googletest//:gtest_main",":rock_paper_scissor"],
)

cc_binary(
    name = "main",
    srcs = ["main.cc"],
    deps = ["@com_github_google_glog//:glog",":rock_paper_scissor","@com_github_gflags_gflags//:gflags"],
)