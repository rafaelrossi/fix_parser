/* @file   fix_protocol_tests.c
   @author Dmitry S. Melnikov, dmitryme@gmail.com
   @date   Created on: 10/01/2012 18:20:02 PM
*/

#include  <check.h>

#include  <fix_parser.h>
#include  <fix_parser_priv.h>
#include  <fix_protocol_descr.h>
#include  <fix_field_tag.h>

START_TEST(FIXProtocolTest1)
{
   FIXParser* p = fix_parser_create(512, 0, 2, 0, 2, 0, PARSER_FLAG_CHECK_ALL);
   fail_unless(p != NULL);
   fail_unless(fix_protocol_init(p, "./data/fix1.xml") == FIX_SUCCESS);
   fail_unless(fix_protocol_get_msg_descr(p, "8") != NULL);
   fail_unless(fix_protocol_get_msg_descr(p, "0") != NULL);
   fail_unless(fix_protocol_get_msg_descr(p, "1") != NULL);
   fail_unless(fix_protocol_get_msg_descr(p, "A") == NULL);
   fail_unless(fix_protocol_get_msg_descr(p, "D") == NULL);
   fail_unless(fix_protocol_get_msg_descr(p, "AE") == NULL);

   fail_unless(!strcmp("FIX1", p->protocol->version));
   fail_unless(!strcmp("FIXT1", p->protocol->transportVersion));

   FIXMsgDescr* msg = fix_protocol_get_msg_descr(p, "8");
   fail_unless(msg != NULL);
   fail_unless(!strcmp(msg->type, "8"));
   fail_unless(!strcmp(msg->name, "ExecutionReport"));
   fail_unless(msg->field_count == 11);

   FIXFieldDescr* field = fix_protocol_get_field_descr(p, msg, FIXFieldTag_BeginString);
   fail_unless(field != NULL);
   fail_unless(field->field_type->tag == FIXFieldTag_BeginString);
   fail_unless(field->field_type->type == FIXFieldValueType_String);
   fail_unless(!strcmp(field->field_type->name, "BeginString"));

   field = fix_protocol_get_field_descr(p, msg, FIXFieldTag_BodyLength);
   fail_unless(field != NULL);
   fail_unless(field->field_type->tag == FIXFieldTag_BodyLength);
   fail_unless(field->field_type->type == FIXFieldValueType_Length);
   fail_unless(!strcmp(field->field_type->name, "BodyLength"));

   field = fix_protocol_get_field_descr(p, msg, FIXFieldTag_MsgType);
   fail_unless(field != NULL);
   fail_unless(field->field_type->tag == FIXFieldTag_MsgType);
   fail_unless(field->field_type->type == FIXFieldValueType_String);
   fail_unless(!strcmp(field->field_type->name, "MsgType"));

   field = fix_protocol_get_field_descr(p, msg, FIXFieldTag_OrderID);
   fail_unless(field != NULL);
   fail_unless(field->field_type->tag == FIXFieldTag_OrderID);
   fail_unless(field->field_type->type == FIXFieldValueType_String);
   fail_unless(!strcmp(field->field_type->name, "OrderID"));

   field = fix_protocol_get_field_descr(p, msg, FIXFieldTag_ClOrdID);
   fail_unless(field != NULL);
   fail_unless(field->field_type->tag == FIXFieldTag_ClOrdID);
   fail_unless(field->field_type->type == FIXFieldValueType_String);
   fail_unless(!strcmp(field->field_type->name, "ClOrdID"));

   field = fix_protocol_get_field_descr(p, msg, FIXFieldTag_SignatureLength);
   fail_unless(field != NULL);
   fail_unless(field->field_type->tag == FIXFieldTag_SignatureLength);
   fail_unless(field->field_type->type == FIXFieldValueType_Length);
   fail_unless(!strcmp(field->field_type->name, "SignatureLength"));

   field = fix_protocol_get_field_descr(p, msg, FIXFieldTag_CheckSum);
   fail_unless(field != NULL);
   fail_unless(field->field_type->tag == FIXFieldTag_CheckSum);
   fail_unless(field->field_type->type == FIXFieldValueType_String);
   fail_unless(!strcmp(field->field_type->name, "CheckSum"));

   fix_parser_free(p);
}
END_TEST

START_TEST(FIXProtocolTest2)
{
   FIXParser* p = fix_parser_create(512, 0, 2, 0, 2, 0, PARSER_FLAG_CHECK_ALL);
   fail_unless(p != NULL);
   fail_unless(fix_protocol_init(p, "./data/fix2.xml") == FIX_SUCCESS);
   fail_unless(fix_protocol_get_msg_descr(p, "8") != NULL);
   fail_unless(fix_protocol_get_msg_descr(p, "0") == NULL);
   fail_unless(fix_protocol_get_msg_descr(p, "1") == NULL);

   fail_unless(!strcmp("FIX2", p->protocol->version));
   fail_unless(!strcmp("FIX2", p->protocol->transportVersion));

   FIXMsgDescr* msg = fix_protocol_get_msg_descr(p, "8");
   fail_unless(msg != NULL);
   fail_unless(!strcmp(msg->type, "8"));
   fail_unless(!strcmp(msg->name, "ExecutionReport"));
   fail_unless(msg->field_count == 11);

   FIXFieldDescr* field = fix_protocol_get_field_descr(p, msg, FIXFieldTag_BeginString);
   fail_unless(field != NULL);
   fail_unless(field->field_type->tag == FIXFieldTag_BeginString);
   fail_unless(field->field_type->type == FIXFieldValueType_String);
   fail_unless(!strcmp(field->field_type->name, "BeginString"));

   field = fix_protocol_get_field_descr(p, msg, FIXFieldTag_BodyLength);
   fail_unless(field != NULL);
   fail_unless(field->field_type->tag == FIXFieldTag_BodyLength);
   fail_unless(field->field_type->type == FIXFieldValueType_Length);
   fail_unless(!strcmp(field->field_type->name, "BodyLength"));

   field = fix_protocol_get_field_descr(p, msg, FIXFieldTag_MsgType);
   fail_unless(field != NULL);
   fail_unless(field->field_type->tag == FIXFieldTag_MsgType);
   fail_unless(field->field_type->type == FIXFieldValueType_String);
   fail_unless(!strcmp(field->field_type->name, "MsgType"));

   field = fix_protocol_get_field_descr(p, msg, FIXFieldTag_OrderID);
   fail_unless(field != NULL);
   fail_unless(field->field_type->tag == FIXFieldTag_OrderID);
   fail_unless(field->field_type->type == FIXFieldValueType_String);
   fail_unless(!strcmp(field->field_type->name, "OrderID"));

   field = fix_protocol_get_field_descr(p, msg, FIXFieldTag_ClOrdID);
   fail_unless(field != NULL);
   fail_unless(field->field_type->tag == FIXFieldTag_ClOrdID);
   fail_unless(field->field_type->type == FIXFieldValueType_String);
   fail_unless(!strcmp(field->field_type->name, "ClOrdID"));

   field = fix_protocol_get_field_descr(p, msg, FIXFieldTag_SignatureLength);
   fail_unless(field != NULL);
   fail_unless(field->field_type->tag == FIXFieldTag_SignatureLength);
   fail_unless(field->field_type->type == FIXFieldValueType_Length);
   fail_unless(!strcmp(field->field_type->name, "SignatureLength"));

   field = fix_protocol_get_field_descr(p, msg, FIXFieldTag_CheckSum);
   fail_unless(field != NULL);
   fail_unless(field->field_type->tag == FIXFieldTag_CheckSum);
   fail_unless(field->field_type->type == FIXFieldValueType_String);
   fail_unless(!strcmp(field->field_type->name, "CheckSum"));

   fix_parser_free(p);
}
END_TEST

Suite* make_fix_protocol_tests_suite()
{
   Suite* s = suite_create("fix_protocol");
   TCase* tc_core = tcase_create("Core");
   tcase_add_test(tc_core, FIXProtocolTest1);
   tcase_add_test(tc_core, FIXProtocolTest2);
   suite_add_tcase(s, tc_core);
   return s;
}