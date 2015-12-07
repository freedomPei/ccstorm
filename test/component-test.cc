// Copyright (c) 2015 ShuMei Inc. All rights reserved.
// Authors: Liang Kun <liangkun@ishumei.com>.

#include <cstdlib>
#include <memory>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <utility>
#include "gtest/gtest.h"
#include "storm/json.h"
#include "storm/exception.h"
#include "storm/tuple.h"
#include "storm/internal/protocol.h"
#include "storm/component.h"

using std::remove;
using std::ostream;
using std::stringstream;
using std::string;
using std::unique_ptr;
using std::vector;
using std::move;
using std::ios_base;
using storm::TopologyContext;
using storm::ProtocolException;
using storm::Value;
using storm::Values;
using storm::g_allocator;
using storm::Tuple;
using namespace storm;
using namespace storm::internal::protocol;

namespace {
    class TestBolt: public Component {
    public:
        TestBolt(): Component() {}  // default constructor
        virtual ~TestBolt() {}
        void Log(const std::string &msg,std::ostream &_os) { internal::protocol::EmitLog(msg, _os); }

    };

    TEST(ComponentTest, Run_Legal) {
         stringstream ssin;
         stringstream ssout;
         ssin << "{\"count\":12}\nend\n";
         TestBolt comp;

         comp.Log("hello,world",ssout);
         json::Value msg = NextMessage(ssout);
         ASSERT_STREQ("hello,world",msg["msg"].GetString());
    }
}

