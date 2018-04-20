--TEST--
CommonMark\Node debug
--FILE--
<?php
$parser = new CommonMark\Parser;
$parser->parse("
Hello World
===========

Paragraph:
  * item
  * item

**strong**
*emphasis*

some inline <html>html</html> is here

```somecode
<?php
some_code();
?>
```

[alt](url \"title\")
![alt](url \"title\")
");

var_dump($parser->finish());
?>
--EXPECT--
object(CommonMark\Node\Document)#2 (1) {
  ["children"]=>
  array(7) {
    [0]=>
    object(CommonMark\Node\Heading)#3 (1) {
      ["children"]=>
      array(1) {
        [0]=>
        object(CommonMark\Node\Text)#10 (1) {
          ["literal"]=>
          string(11) "Hello World"
        }
      }
    }
    [1]=>
    object(CommonMark\Node\Paragraph)#4 (1) {
      ["children"]=>
      array(1) {
        [0]=>
        object(CommonMark\Node\Text)#10 (1) {
          ["literal"]=>
          string(10) "Paragraph:"
        }
      }
    }
    [2]=>
    object(CommonMark\Node\BulletList)#5 (1) {
      ["children"]=>
      array(2) {
        [0]=>
        object(CommonMark\Node\Item)#10 (1) {
          ["children"]=>
          array(1) {
            [0]=>
            object(CommonMark\Node\Paragraph)#12 (1) {
              ["children"]=>
              array(1) {
                [0]=>
                object(CommonMark\Node\Text)#13 (1) {
                  ["literal"]=>
                  string(4) "item"
                }
              }
            }
          }
        }
        [1]=>
        object(CommonMark\Node\Item)#11 (1) {
          ["children"]=>
          array(1) {
            [0]=>
            object(CommonMark\Node\Paragraph)#12 (1) {
              ["children"]=>
              array(1) {
                [0]=>
                object(CommonMark\Node\Text)#13 (1) {
                  ["literal"]=>
                  string(4) "item"
                }
              }
            }
          }
        }
      }
    }
    [3]=>
    object(CommonMark\Node\Paragraph)#6 (1) {
      ["children"]=>
      array(3) {
        [0]=>
        object(CommonMark\Node\Text\Strong)#11 (1) {
          ["children"]=>
          array(1) {
            [0]=>
            object(CommonMark\Node\Text)#13 (1) {
              ["literal"]=>
              string(6) "strong"
            }
          }
        }
        [1]=>
        object(CommonMark\Node\SoftBreak)#10 (0) {
        }
        [2]=>
        object(CommonMark\Node\Text\Emphasis)#12 (1) {
          ["children"]=>
          array(1) {
            [0]=>
            object(CommonMark\Node\Text)#13 (1) {
              ["literal"]=>
              string(8) "emphasis"
            }
          }
        }
      }
    }
    [4]=>
    object(CommonMark\Node\Paragraph)#7 (1) {
      ["children"]=>
      array(5) {
        [0]=>
        object(CommonMark\Node\Text)#12 (1) {
          ["literal"]=>
          string(12) "some inline "
        }
        [1]=>
        object(CommonMark\Node\HTMLInline)#10 (1) {
          ["literal"]=>
          string(6) "<html>"
        }
        [2]=>
        object(CommonMark\Node\Text)#11 (1) {
          ["literal"]=>
          string(4) "html"
        }
        [3]=>
        object(CommonMark\Node\HTMLInline)#13 (1) {
          ["literal"]=>
          string(7) "</html>"
        }
        [4]=>
        object(CommonMark\Node\Text)#14 (1) {
          ["literal"]=>
          string(8) " is here"
        }
      }
    }
    [5]=>
    object(CommonMark\Node\CodeBlock)#8 (2) {
      ["fence"]=>
      string(8) "somecode"
      ["literal"]=>
      string(22) "<?php
some_code();
?>
"
    }
    [6]=>
    object(CommonMark\Node\Paragraph)#9 (1) {
      ["children"]=>
      array(3) {
        [0]=>
        object(CommonMark\Node\Link)#14 (3) {
          ["url"]=>
          string(3) "url"
          ["title"]=>
          string(5) "title"
          ["children"]=>
          array(1) {
            [0]=>
            object(CommonMark\Node\Text)#10 (1) {
              ["literal"]=>
              string(3) "alt"
            }
          }
        }
        [1]=>
        object(CommonMark\Node\SoftBreak)#13 (0) {
        }
        [2]=>
        object(CommonMark\Node\Image)#11 (3) {
          ["url"]=>
          string(3) "url"
          ["title"]=>
          string(5) "title"
          ["children"]=>
          array(1) {
            [0]=>
            object(CommonMark\Node\Text)#10 (1) {
              ["literal"]=>
              string(3) "alt"
            }
          }
        }
      }
    }
  }
}
