/***************************************************************************
 *                                  _   _ ____  _
 *  Project                     ___| | | |  _ \| |
 *                             / __| | | | |_) | |
 *                            | (__| |_| |  _ <| |___
 *                             \___|\___/|_| \_\_____|
 *
 * Copyright (C) Daniel Stenberg, <daniel@haxx.se>, et al.
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution. The terms
 * are also available at https://curl.se/docs/copyright.html.
 *
 * You may opt to use, copy, modify, merge, publish, distribute and/or sell
 * copies of the Software, and permit persons to whom the Software is
 * furnished to do so, under the terms of the COPYING file.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 * SPDX-License-Identifier: curl
 *
 ***************************************************************************/
#include "curlcheck.h"
#include "http_aws_sigv4.h"
#include "dynbuf.h"

struct dynbuf canonical_path;

static CURLcode unit_setup(void)
{
  Curl_dyn_init(&canonical_path, CURL_MAX_HTTP_HEADER);
  return CURLE_OK;
}

static void unit_stop(void)
{
}

UNITTEST_START
{

  /**
   * testing canon_string
   * case 1:
   * handle //example// correctly (get-slashes-normalized)
  */
 const char *path = "//example//";
 const char *correct_path = "/example/";
 Curl_canon_string(path, strlen(path), &canonical_path, NULL);
 fail_unless(strcmp(Curl_dyn_ptr(&canonical_path), correct_path),
 "Not normalizing slashes correctly");

}
UNITTEST_STOP
