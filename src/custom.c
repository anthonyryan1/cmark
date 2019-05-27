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
#ifndef PHP_CMARK_NODE_CUSTOM
#define PHP_CMARK_NODE_CUSTOM

#include <php.h>

#include <cmark.h>

#include <src/common.h>
#include <src/node.h>
#include <src/custom.h>
#include <src/handlers.h>

zend_object_handlers php_cmark_node_custom_handlers;

zend_object* php_cmark_node_custom_create(zend_class_entry *ce) {
	php_cmark_node_custom_t *n = 
		(php_cmark_node_custom_t*) 
			ecalloc(1, sizeof(php_cmark_node_custom_t));

	zend_object_std_init(
		php_cmark_node_zend(&n->h), ce);

	n->h.std.handlers = &php_cmark_node_custom_handlers;

	return php_cmark_node_zend(&n->h);
}

zval* php_cmark_node_custom_read(zval *object, zval *member, int type, void **rtc, zval *rv) {
	php_cmark_node_custom_t *n = php_cmark_node_custom_fetch(object);

	if (Z_TYPE_P(member) != IS_STRING) {
		goto php_cmark_node_custom_read_error;
	}

	if (EXPECTED(rtc)) {
		if (RTC(rtc, cmark_node_get_on_enter))
			return php_cmark_node_read_str(&n->h, 
				cmark_node_get_on_enter, &n->onEnter, rv);
		if (RTC(rtc, cmark_node_get_on_exit))
			return php_cmark_node_read_str(&n->h, 
				cmark_node_get_on_exit, &n->onLeave, rv);
	}

	if (zend_string_equals_literal(Z_STR_P(member), "onEnter")) {
		return php_cmark_node_read_str(&n->h, 
			RTS(rtc, cmark_node_get_on_enter), &n->onEnter, rv);
	} else if (zend_string_equals_literal(Z_STR_P(member), "onLeave")) {
		return php_cmark_node_read_str(&n->h, 
			RTS(rtc, cmark_node_get_on_exit), &n->onLeave, rv);
	}

php_cmark_node_custom_read_error:
	return php_cmark_node_read(object, member, type, rtc, rv);
}

#if PHP_VERSION_ID >= 70400
zval* php_cmark_node_custom_write(zval *object, zval *member, zval *value, void **rtc) {
#else
void php_cmark_node_custom_write(zval *object, zval *member, zval *value, void **rtc) {
#endif
	php_cmark_node_custom_t *n = php_cmark_node_custom_fetch(object);

	if (EXPECTED(rtc)) {
		if (RTC(rtc, cmark_node_set_on_enter)) {
			php_cmark_assert_type(value, IS_STRING, 0, 
#if PHP_VERSION_ID >= 70400
                return &EG(uninitialized_zval),
#else
                return,
#endif
				"onEnter expected to be string");
			php_cmark_node_write_str(&n->h, 
				cmark_node_set_on_enter, value, &n->onEnter);
#if PHP_VERSION_ID >= 70400
			return value;
#else
			return;
#endif
		} else if (RTC(rtc, cmark_node_set_on_exit)) {
			php_cmark_assert_type(value, IS_STRING, 0, 
#if PHP_VERSION_ID >= 70400
                return &EG(uninitialized_zval),
#else
                return,
#endif
				"onLeave expected to be string");
			php_cmark_node_write_str(&n->h, 
				cmark_node_set_on_exit, value, &n->onLeave);
#if PHP_VERSION_ID >= 70400
			return value;
#else
			return;
#endif
		}	
	}

	if (Z_TYPE_P(member) == IS_STRING) {
		if (zend_string_equals_literal(Z_STR_P(member), "onEnter")) {
			php_cmark_assert_type(value, IS_STRING, 0, 
#if PHP_VERSION_ID >= 70400
                return &EG(uninitialized_zval),
#else
                return,
#endif
				"onEnter expected to be string");
			php_cmark_node_write_str(&n->h, 
				RTS(rtc, cmark_node_set_on_enter), value, &n->onEnter);
#if PHP_VERSION_ID >= 70400
			return value;
#else
			return;
#endif
		} else if (zend_string_equals_literal(Z_STR_P(member), "onLeave")) {
			php_cmark_assert_type(value, IS_STRING, 0, 
#if PHP_VERSION_ID >= 70400
                return &EG(uninitialized_zval),
#else
                return,
#endif
				"onLeave expected to be string");
			php_cmark_node_write_str(&n->h, 
				RTS(rtc, cmark_node_set_on_exit), value, &n->onLeave);
#if PHP_VERSION_ID >= 70400
			return value;
#else
			return;
#endif
		}
	}

#if PHP_VERSION_ID >= 70400
    return php_cmark_node_write(object, member, value, rtc);
#else
	php_cmark_node_write(object, member, value, rtc);
#endif
}

int php_cmark_node_custom_isset(zval *object, zval *member, int has_set_exists, void **rtc) {
	php_cmark_node_custom_t *n = php_cmark_node_custom_fetch(object);
	zval *zv = &EG(uninitialized_zval);

	if (Z_TYPE_P(member) != IS_STRING) {
		return 0;
	}

	if (EXPECTED(rtc)) {
		if (RTC(rtc, cmark_node_get_on_enter)) {
			zv = php_cmark_node_read_str(&n->h, 
				cmark_node_get_on_enter, &n->onEnter, NULL);
			goto php_cmark_node_custom_isset_result;
		} else if (RTC(rtc, cmark_node_get_on_exit)) {
			zv = php_cmark_node_read_str(&n->h, 
				cmark_node_get_on_exit, &n->onLeave, NULL);
			goto php_cmark_node_custom_isset_result;
		}
	}

	if (zend_string_equals_literal(Z_STR_P(member), "onEnter")) {
		zv = php_cmark_node_read_str(&n->h, 
			RTS(rtc, cmark_node_get_on_enter), &n->onEnter, NULL);
	} else if (zend_string_equals_literal(Z_STR_P(member), "onLeave")) {
		zv = php_cmark_node_read_str(&n->h, 
			RTS(rtc, cmark_node_get_on_exit), &n->onLeave, NULL);
	}

php_cmark_node_custom_isset_result:
	if (Z_TYPE_P(zv) == IS_STRING) {
		return 1;
	}

	return php_cmark_node_isset(object, member, has_set_exists, rtc);
}

void php_cmark_node_custom_unset(zval *object, zval *member, void **rtc) {
	php_cmark_node_custom_t *n = php_cmark_node_custom_fetch(object);

	if (Z_TYPE_P(member) != IS_STRING) {
		goto php_cmark_node_custom_unset_error;
	}

	if (EXPECTED(rtc)) {
		if (RTC(rtc, cmark_node_set_on_enter)) {
			php_cmark_node_write_str(&n->h, 
				cmark_node_set_on_enter, NULL, &n->onEnter);
			return;
		} else if (RTC(rtc, cmark_node_set_on_exit)) {
			php_cmark_node_write_str(&n->h, 
				cmark_node_set_on_exit, NULL, &n->onLeave);
			return;
		}
	}

	if (zend_string_equals_literal(Z_STR_P(member), "onEnter")) {
		php_cmark_node_write_str(&n->h, 
			RTS(rtc, cmark_node_set_on_enter), NULL, &n->onEnter);
		return;
	} else if (zend_string_equals_literal(Z_STR_P(member), "onLeave")) {
		php_cmark_node_write_str(&n->h, 
			RTS(rtc, cmark_node_set_on_exit), NULL, &n->onLeave);
		return;
	}

php_cmark_node_custom_unset_error:
	return php_cmark_node_unset(object, member, rtc);
}

PHP_MINIT_FUNCTION(CommonMark_Node_Custom)
{	
	memcpy(&php_cmark_node_custom_handlers, &php_cmark_node_handlers, sizeof(zend_object_handlers));

	php_cmark_node_custom_handlers.read_property = php_cmark_node_custom_read;
	php_cmark_node_custom_handlers.write_property = php_cmark_node_custom_write;
	php_cmark_node_custom_handlers.has_property = php_cmark_node_custom_isset;
	php_cmark_node_custom_handlers.unset_property = php_cmark_node_custom_unset;

	return SUCCESS;
}

PHP_RINIT_FUNCTION(CommonMark_Node_Custom)
{
	return SUCCESS;
}
#endif
