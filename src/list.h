/*
  +----------------------------------------------------------------------+
  | cmark                                                                |
  +----------------------------------------------------------------------+
  | Copyright (c) Joe Watkins 2018                                       |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: krakjoe <krakjoe@php.net>                                    |
  +----------------------------------------------------------------------+
 */
#ifndef PHP_CMARK_LIST_H
#define PHP_CMARK_LIST_H

#include <cmark.h>

extern zend_class_entry *php_cmark_node_list_ordered_ce;
extern zend_class_entry *php_cmark_node_list_bullet_ce;

extern PHP_MINIT_FUNCTION(CommonMark_Node_List);
extern PHP_RINIT_FUNCTION(CommonMark_Node_List);
#endif
