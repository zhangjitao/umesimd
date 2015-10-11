﻿// The MIT License (MIT)
//
// Copyright (c) 2015 CERN
//
// Author: Przemyslaw Karpinski
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
//
//  This piece of code was developed as part of ICE-DIP project at CERN.
//  "ICE-DIP is a European Industrial Doctorate project funded by the European Community's 
//  7th Framework programme Marie Curie Actions under grant PITN-GA-2012-316596".
//

#ifndef UME_UNIT_TEST_SIMD_64B_H_
#define UME_UNIT_TEST_SIMD_64B_H_

#include "UMEUnitTestCommon.h"

int test_UME_SIMD64b(bool supressMessages);

int test_UME_SIMD8_8(bool supressMessages);
int test_UME_SIMD8_8u(bool supressMessages);
int test_UME_SIMD8_8i(bool supressMessages);

int test_UME_SIMD4_16(bool supressMessages);
int test_UME_SIMD4_16u(bool supressMessages);
int test_UME_SIMD4_16i(bool supressMessages);

int test_UME_SIMD2_32(bool supressMessages);
int test_UME_SIMD2_32u(bool supressMessages);
int test_UME_SIMD2_32i(bool supressMessages);
int test_UME_SIMD2_32f(bool supressMessages);

int test_UME_SIMD1_64(bool supressMessages);
int test_UME_SIMD1_64u(bool supressMessages);
int test_UME_SIMD1_64i(bool supressMessages);
int test_UME_SIMD1_64f(bool supressMessages);

using namespace UME::SIMD;

int test_UME_SIMD64b(bool supressMessages)
{
    int simd8_8_res = test_UME_SIMD8_8(supressMessages);
    int simd4_16_res = test_UME_SIMD4_16(supressMessages);
    int simd2_32_res = test_UME_SIMD2_32(supressMessages);
    int simd1_64_res = test_UME_SIMD1_64(supressMessages);

    return simd8_8_res + simd4_16_res + simd2_32_res + simd1_64_res;
}

int test_UME_SIMD8_8(bool supressMessages)
{
    int fail_u = test_UME_SIMD8_8u(supressMessages);
    int fail_i = test_UME_SIMD8_8i(supressMessages);

    return fail_u + fail_i;
}

int test_UME_SIMD4_16(bool supressMessages)
{
    int fail_u = test_UME_SIMD4_16u(supressMessages);
    int fail_i = test_UME_SIMD4_16u(supressMessages);
    
    return fail_u + fail_i;
}

int test_UME_SIMD2_32(bool supressMessages)
{
    int fail_u = test_UME_SIMD2_32u(supressMessages);
    int fail_i = test_UME_SIMD2_32i(supressMessages);
    int fail_f = test_UME_SIMD2_32f(supressMessages);

    return fail_u + fail_i + fail_f;
}

int test_UME_SIMD1_64(bool supressMessages)
{
    int fail_u = test_UME_SIMD1_64u(supressMessages);
    int fail_i = test_UME_SIMD1_64i(supressMessages);
    int fail_f = test_UME_SIMD1_64f(supressMessages);

    return fail_u + fail_i + fail_f;
}

// ****************************************************************************
// * Test functions for specific vector types
// ****************************************************************************

int test_UME_SIMD8_8u(bool supressMessages) {
    char header[] = "UME::SIMD::SIMD8_8u test";
    INIT_TEST(header, supressMessages);
    
    {
        SIMD8_8u vec0;
        CHECK_CONDITION(vec0.length() == 8, "ZERO-CONSTR");
    }

    return g_failCount;
}

int test_UME_SIMD8_8i(bool supressMessages) {
    char header[] = "UME::SIMD::SIMD8_8i test";
    INIT_TEST(header, supressMessages);
    
    {
        SIMD8_8i vec0;
        CHECK_CONDITION(vec0.length() == 8, "ZERO-CONSTR");
    }

    return g_failCount;
}

int test_UME_SIMD4_16u(bool supressMessages) {
    char header[] = "UME::SIMD::SIMD4_16u test";
    INIT_TEST(header, supressMessages);
    
    {
        SIMD4_16u vec0;
        CHECK_CONDITION(vec0.length() == 4, "ZERO-CONSTR");
    }

    return g_failCount;
}

int test_UME_SIMD4_16i(bool supressMessages) {
    char header[] = "UME::SIMD::SIMD4_16i test";
    INIT_TEST(header, supressMessages);
    
    {
        SIMD4_16i vec0;
        CHECK_CONDITION(vec0.length() == 4, "ZERO-CONSTR");
    }

    return g_failCount;
}

int test_UME_SIMD2_32u(bool supressMessages) {
    char header[] = "UME::SIMD::SIMD2_32u test";
    INIT_TEST(header, supressMessages);
    
    {
        SIMD2_32u vec0;
        CHECK_CONDITION(vec0.length() == 2, "ZERO-CONSTR");
    }
    genericUintTest<SIMD2_32u, uint32_t, SIMDMask2, 2, DataSet_1_32u>();

    return g_failCount;
}

int test_UME_SIMD2_32i(bool supressMessages) {
    char header[] = "UME::SIMD::SIMD2_32i test";
    INIT_TEST(header, supressMessages);
    
    {
        SIMD2_32i vec0;
        CHECK_CONDITION(vec0.length() == 2, "ZERO-CONSTR");
    }

    return g_failCount;
}

int test_UME_SIMD2_32f(bool supressMessages) {
    char header[] = "UME::SIMD::SIMD2_32f test";
    INIT_TEST(header, supressMessages);
    
    {
        SIMD2_32f vec0;
        CHECK_CONDITION(vec0.length() == 2, "ZERO-CONSTR");
    }

    {
        SIMD1_32f vec0(3.14f);
        SIMD1_32f vec1(2.71f);
        SIMD2_32f vec2;

        vec2.pack(vec0, vec1);
        CHECK_CONDITION( vec2[0] > 3.13f && vec2[0] < 3.15f &&
                         vec2[1] > 2.70f && vec2[1] < 2.72f, "PACK");
    }

    genericFloatTest<SIMD2_32f, float, SIMD2_32i, SIMDMask2, 2, DataSet_1_32f>();
   
    return g_failCount;
}

int test_UME_SIMD1_64u(bool supressMessages) {
    char header[] = "UME::SIMD::SIMD1_64u test";
    INIT_TEST(header, supressMessages);

    {
        SIMD1_64u vec0;
        CHECK_CONDITION(vec0.length() == 1, "ZERO-CONSTR");
    }

    return g_failCount;
}


int test_UME_SIMD1_64i(bool supressMessages) {
    char header[] = "UME::SIMD::SIMD1_64i test";
    INIT_TEST(header, supressMessages);

    {
        SIMD1_64i vec0;
        CHECK_CONDITION(vec0.length() == 1, "ZERO-CONSTR");
    }

    return g_failCount;
}

int test_UME_SIMD1_64f(bool supressMessages) {
    char header[] = "UME::SIMD::SIMD1_64f test";
    INIT_TEST(header, supressMessages);

    {
        SIMD1_64f vec0;
        CHECK_CONDITION(vec0.length() == 1, "ZERO-CONSTR");
    }

    return g_failCount;
}

#endif
