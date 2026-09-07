from pygments.style import Style
from pygments.token import Comment, Keyword, Name, Number, Operator, String, Text


class NetomacStyle(Style):
    """Pygments style approximating the PSS(R)NETOMAC editor's colors."""

    background_color = "#ffffff"
    default_style = ""

    styles = {
        Text:            "#000000",
        Comment:         "noitalic #01893a",   # $ ... and ! ... lines
        Keyword:         "#ff2640",     # [[Section]] headers
        Operator:        "#696969",     # @ and @@
        Name.Variable:   "#000000",          # #Vn, #Rc, #\MAC\...
        String:          "#b64d39",          # 'VSrc', 'IBR'
        Number:          "#000000",
        Name.Builtin: "#007eb1",
    }
