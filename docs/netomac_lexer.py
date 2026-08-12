from pygments.lexer import RegexLexer from pygments.token import Comment, Keyword, Name, Number, Text from pygments.lexers import _mappingclass NetomacLexer(RegexLexer):
    name = "Netomac"aliases = ["netomac"]

    tokens = {
        "root": [
            (r"\$.*?$", Comment),
            (r"@@", Keyword),
            (r"#[A-Za-z_][A-Za-z0-9_]*", Name.Variable),
            (r"\b\d+(\.\d+)?([eE][+-]?\d+)?\b", Number),
            (r"!.*?$", Comment),
            (r"\s+", Text),
            (r".", Text),
        ]
    }

def setup(app):
    from sphinx.highlighting import lexerslexers["netomac"] = NetomacLexer()

    return {
        "version": "1.0",
        "parallel_read_safe": True,
    }