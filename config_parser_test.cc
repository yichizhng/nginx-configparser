#include "gtest/gtest.h"
#include "config_parser.h"

TEST(NginxConfigParserTest, SimpleConfig) {
  NginxConfigParser parser;
  NginxConfig out_config;

  bool success = parser.Parse("example_config", &out_config);

  EXPECT_TRUE(success);
}

TEST(NginxConfigParserTest, NestedBraces) {
  NginxConfigParser parser;
  NginxConfig out_config;
  
  bool success = parser.Parse("testconfig1", &out_config);

  EXPECT_TRUE(success);
}

TEST(NginxConfigParserTest, CommentTest) {
  NginxConfigParser parser;
  NginxConfig out_config;
  
  bool success = parser.Parse("testconfig2", &out_config);

  EXPECT_TRUE(success);

  EXPECT_STREQ("foo \"bar\";\nserver {\n  listen 80;\n  server_name foo.com;\n  root /home/ubuntu/sites/foo/;\n}\n", out_config.ToString(0).c_str());
}

