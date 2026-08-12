from pygments.lexer import RegexLexer
from pygments.token import Comment, Keyword, Name, Number, Operator, String, Text


class NetomacLexer(RegexLexer):
    name = "Netomac"
    aliases = ["netomac"]
    filenames = ["*.net"]

    tokens = {
        "root": [
            (r"\$.*?$", Comment),
            (r"!.*?$", Comment),
            (r"\[\[.*?\]\]", Keyword),          # [[Feeder]], [[End Network]] ...
            (r"@@", Operator),                   # global-parameter assignment
            (r"@", Operator),                    # local/model parameter assignment
            (r"#[A-Za-z_][A-Za-z0-9_.\\]*", Name.Variable),  # #Vn, #\MAC\..., etc.
            (r"'[^']*'", String),                # 'VSrc', 'IBR', ...
            (r"\b\d+(\.\d+)?([eE][+-]?\d+)?\b", Number),
            (r"\s+", Text),
            (r".", Text),
        ]
    }


def setup(app):
    from sphinx.highlighting import lexers

    lexers["netomac"] = NetomacLexer()

    return {
        "version": "1.0",
        "parallel_read_safe": True,
    }