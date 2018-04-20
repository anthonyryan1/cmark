--TEST--
CommonMark\Node\CustomInline clone
--FILE--
<?php
$para = new CommonMark\Node\Paragraph;

$node = new CommonMark\Node\CustomInline;
$node->onEnter = "ENTER";
$node->onLeave = "LEAVE";
$node->appendChild(
	new CommonMark\Node\Text("NODE"));

$para->appendChild($node);

var_dump($para, clone $para);
?>
--EXPECT--
object(CommonMark\Node\Paragraph)#1 (1) {
  ["children"]=>
  array(1) {
    [0]=>
    object(CommonMark\Node\CustomInline)#4 (3) {
      ["enter"]=>
      string(5) "ENTER"
      ["leave"]=>
      string(5) "LEAVE"
      ["children"]=>
      array(1) {
        [0]=>
        object(CommonMark\Node\Text)#5 (1) {
          ["literal"]=>
          string(4) "NODE"
        }
      }
    }
  }
}
object(CommonMark\Node\Paragraph)#3 (1) {
  ["children"]=>
  array(1) {
    [0]=>
    object(CommonMark\Node\CustomInline)#4 (3) {
      ["enter"]=>
      string(5) "ENTER"
      ["leave"]=>
      string(5) "LEAVE"
      ["children"]=>
      array(1) {
        [0]=>
        object(CommonMark\Node\Text)#5 (1) {
          ["literal"]=>
          string(4) "NODE"
        }
      }
    }
  }
}
