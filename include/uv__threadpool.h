/* Copyright 2015 Samsung Electronics Co., Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/* Copyright Joyent, Inc. and other Node contributors. All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#ifndef __uv__threadpool_header__
#define __uv__threadpool_header__


#ifdef __cplusplus
extern "C" {
#endif


void uv__work_submit(uv_loop_t* loop,
                     struct uv__work *w,
                     void (*work)(struct uv__work *w),
                     void (*done)(struct uv__work *w, int status));

void uv__work_done(uv_async_t* handle);


/*
 * uv_work_t is a subclass of uv_req_t.
 */
struct uv_work_s {
  UV_REQ_FIELDS
  uv_loop_t* loop;
  uv_work_cb work_cb;
  uv_after_work_cb after_work_cb;
  UV_WORK_PRIVATE_FIELDS
};


int uv_queue_work(uv_loop_t* loop,
                  uv_work_t* req,
                  uv_work_cb work_cb,
                  uv_after_work_cb after_work_cb);

int uv_cancel(uv_req_t* req);


/*
 * for embed systems that need cleanup before exit
 */
#if defined(__NUTTX__) || defined(__TUV_RAW__)
void uv_cleanup(void);
#endif

#ifdef __cplusplus
}
#endif


#endif /* __uv__threadpool_header__ */
