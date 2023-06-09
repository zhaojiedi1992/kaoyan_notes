# Configuration file for the Sphinx documentation builder.
#
# For the full list of built-in configuration values, see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Project information -----------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#project-information

project = '考研笔记_赵杰迪'
copyright = '2023, 1072892917@qq.com'
author = '1072892917@qq.com'
release = 'v1.0'

# -- General configuration ---------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#general-configuration

extensions = []

templates_path = ['_templates']
exclude_patterns = [
     'sphinx.ext.imgmath',
]

language = 'zh_cn'

# -- Options for HTML output -------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#options-for-html-output

html_theme = 'sphinx_rtd_theme'
html_static_path = ['_static']

html_css_files = [
    'css/s4defs-roles.css',
    'css/hacks.css',
    ]



rst_prolog = """
 .. include:: <s5defs.txt>

 """