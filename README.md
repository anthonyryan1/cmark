cmark
=====
*CommonMark API*

[![Build Status](https://travis-ci.org/krakjoe/cmark.svg?branch=master)](https://travis-ci.org/krakjoe/cmark)
[![Coverage Status](https://coveralls.io/repos/github/krakjoe/cmark/badge.svg)](https://coveralls.io/github/krakjoe/cmark)

Requires
========

  * libcmark

Build
=====

  * `./configure --with-cmark=/path/to/cmark/install --with-php-config=/path/to/php-config`
  * `make install`

API
===

```
namespace CommonMark\Node {

	final class Document 		extends \CommonMark\Node {}

	const Lists\Delimit\Period;
	const Lists\Delimit\Paren;

	final class BulletList 		extends \CommonMark\Node {
		public $tight;
		public $delimiter;
	}

	final class OrderedList		extends \CommonMark\Node {
		public $tight;
		public $delimiter;
		public $start;
	}

	final class Item		extends \CommonMark\Node {}

	final class Heading		extends \CommonMark\Node {
		public $level;
	}

	final class BlockQuote		extends \CommonMark\Node {}
	final class Paragraph		extends \CommonMark\Node {}

	final class Strong		extends \CommonMark\Node {}
	final class Emphasis		extends \CommonMark\Node {}
	final class ThematicBreak	extends \CommonMark\Node {}
	final class SoftBreak		extends \CommonMark\Node {}
	final class LineBreak		extends \CommonMark\Node {}

	final class Text 		extends \CommonMark\Node {
		public $literal;

		public function __construct();
		public function __construct(string $literal);
	}

	final class Code		extends Text {}
	final class HTMLBlock		extends Text {}
	final class HTMLInline		extends Text {}

	final class CodeBlock		extends Text {
		public $fence;

		public function __construct(string $fence, string $literal);
	}

	final class Image		extends \CommonMark\Node {
		public $url;
		public $title;
	}

	final class Link		extends \CommonMark\Node {
		public $url;
		public $title;
	}

	final class CustomBlock		extends \CommonMark\Node {
		public $onEnter;
		public $onLeave;
	}

	final class CustomInline	extends \CommonMark\Node {
		public $onEnter;
		public $onLeave;
	}
}

namespace CommonMark\Interfaces {

	final interface IVisitor {
		const Done;
		const Enter;
		const Leave;

		public function enter(\CommonMark\Node $node);
		public function leave(\CommonMark\Node $node);
	}

	final interface IVisitable {
		public function accept(CommonMark\Interfaces\IVisitor $visitor);
	}
}

namespace CommonMark {

	final abstract class Node implements \CommonMark\Interfaces\IVisitable, \Traversable {
		public $parent;
		public $previous;
		public $next;
		public $firstChild;
		public $lastChild;

		public $startLine;
		public $endLine;
		public $startColumn;
		public $endColumn;

		public function appendChild(Node $child) : Node;
		public function prependChild(Node $child) : Node;

		public function insertBefore(Node $sibling) : Node;
		public function insertAfter(Node $sibling) : Node;

		public function replace(Node $node) : Node;
		public function unlink() : void;

		public function accept(\CommonMark\Interfaces\IVisitor $visitor);
	}

	final class Parser {
		public function __construct();
		public function __construct(int $options);

		public function parse(string $content);
		public function finish() : \CommonMark\Node\Document;
	}

	const Parser\Normal;
	const Parser\Normalize;
	const Parser\ValidateUTF8;
	const Parser\Smart;

	function Parse(string $content, int $options = Parser\Normal) : \CommonMark\Node\Document;

	const Render\Normal;
	const Render\SourcePos;
	const Render\HardBreaks;
	const Render\Safe;
	const Render\NoBreaks;

	function Render(Node $node, int $options = Render\Normal, int $width = 0) : string;
	function Render\HTML(Node $node) : string;
	function Render\XML(Node $node) : string;
	function Render\Latex(Node $node, int $options = Render\Normal, int $width = 0) : string;
	function Render\Man(Node $node, int $options = Render\Normal, int $width = 0) : string;
}

```
