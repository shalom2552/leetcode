import re
import os

SOURCE_FILE = 'README.md'
OUTPUT_FILE = '../readme.md'
GITHUB_USER = 'shalom2552'
REPO_NAME = 'leetcode'
BRANCH = 'main'

BASE_URL = f'https://github.com/{GITHUB_USER}/{REPO_NAME}/blob/{BRANCH}/'

def main():
    if not os.path.exists(SOURCE_FILE):
        print(f"Error: Could not find '{SOURCE_FILE}'.")
        print("Make sure you are running this script from the folder *above* the leetcode repo.")
        return

    with open(SOURCE_FILE, 'r', encoding='utf-8') as f:
        content = f.read()

    pattern = r'\]\((?!http|#)([^)]+)\)'

    def add_base_url(match):
        relative_path = match.group(1)
        return f']({BASE_URL}{relative_path})'

    new_content = re.sub(pattern, add_base_url, content)

    with open(OUTPUT_FILE, 'w', encoding='utf-8') as f:
        f.write(new_content)

    print(f"Success! Generated '{OUTPUT_FILE}' with absolute links.")
    return

if __name__ == '__main__':
    main()

